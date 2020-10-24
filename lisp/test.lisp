
;; define database global var
(defvar *db* nil)

;; to generate rows for db
(defun make-cd (title artist rating ripped)
  (list :title title :artist artist :rating rating :ripped ripped))

;; insert row
(defun add-record (cd)
  (push cd *db*))

;; take db dump
(defun dump-db ()
  (dolist (cd *db*)
    (format *standard-output* "~{~a:~10t~a~%~}~%" cd)))

;; prompt cl for a filed
(defun prompt-read (prompt)
  (format *query-io* "~a: " prompt)
  (force-output *query-io*)
  (read-line *query-io*))

;; prompt cl for a cd
(defun prompt-for-cd ()
  (make-cd
   (prompt-read "Title")
   (prompt-read "Artist")
   (or (parse-integer (prompt-read "Rating") :junk-allowed t) 0)
   (y-or-n-p "Ripped")))

;; continuously add rows to db
(defun add-cds ()
  (loop (add-record (prompt-for-cd))
        (if (not (y-or-n-p "Insert more?")) (return)) ))

;; save database to file
(defun save-db (filename)
  (with-open-file (out filename
                       :direction :output
                       :if-exists :supersede)
    (with-standard-io-syntax (print *db* out))))

;; load database from file
(defun load-db (filename)
  (with-open-file (in filename
                      :direction :input) ;; default direction -> input
    (with-standard-io-syntax (setf *db* (read in)))))


;; dataaccess: selection by artist
(defun select-by-artist (artist)
  (remove-if-not #'(lambda (cd) (equal (getf cd :artist) artist)) *db*))

;; general purpose queries
(defun select (selector-fn)
  (remove-if-not selector-fn *db*))

;; (defun where (&key title artist rating (ripped nil ripped-p))
;;   #'(lambda (cd)
;;     (and
;;      (if title (equal (getf cd :title) title) t)
;;      (if artist (equal (getf cd :artist) artist) t)
;;      (if rating (equal (getf cd :rating) rating) t)
;;      (if ripped-p (equal (getf cd :ripped) ripped) t))))
;; example: (select (where :artist "eminem" :rating 4))

;; update cd in db
(defun update (selector-fn &key title artist rating (ripped nil ripped-p))
  (setf *db*
        (mapcar
         #'(lambda (row)
             (when (funcall selector-fn row)
               (if title    (setf (getf row :title) title))
               (if artist   (setf (getf row :artist) artist))
               (if rating   (setf (getf row :rating) rating))
               (if ripped-p (setf (getf row :ripped) ripped)))
             row) *db*)))

;; delete rows from db
(defun delete-rows (selector-fn)
  (setf *db* (remove-if selector-fn *db*)))


;; implementation `where'
(defun make-comparison-expr (field value)
  `(equal (getf cd ,field) ,value))
(defun make-comparisons-list (fields)
  (loop while fields
        collecting (make-comparison-expr (pop fields) (pop fields))))
(defmacro where (&rest clauses)
  `#'(lambda (cd) (and ,@(make-comparisons-list clauses))))
