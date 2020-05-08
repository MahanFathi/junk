#include <iostream>
#include <Eigen/Core>
#include <Eigen/Core>

typedef Eigen::Matrix<double, 2, 2> mat_1_2x2;
typedef Eigen::Matrix<double, 2, 2> mat_2_2x2;

void printMat(mat_1_2x2 m) {
    std::cout << m << '\n';
}

int main(int argc, char *argv[]) {

    typedef Eigen::Matrix<int, 5, Eigen::Dynamic> Mat5;

    //==============================
    //          Initilize
    //==============================
    Eigen::MatrixXf n(7,5);
    Eigen::MatrixXf m(5,5);
    m << (Eigen::Matrix3f() << 1, 2, 3, 4, 5, 6, 7, 8, 9).finished(),
        Eigen::MatrixXf::Zero(3,2),
        Eigen::MatrixXf::Zero(2,3),
        Eigen::MatrixXf::Identity(2,2);
    n << m, Eigen::MatrixXf::Zero(2,5);
    std::cout << n << '\n';
    std::cout << m.rows() << '\n';

    Eigen::MatrixXd mat(3,3);
    mat << 1,2,3,4,5,6,7,8,9;
    std::cout << mat << '\n';
    Eigen::VectorXd v = Eigen::VectorXd::Ones(3);
    std::cout << mat * v << '\n';
    // mat = mat * mat;
    // std::cout << mat << '\n';
    Eigen::MatrixXd tmp = mat;
    mat.noalias() = tmp * tmp;
    std::cout << mat << '\n';
    tmp = tmp * tmp;
    std::cout << mat << '\n';
    mat.array() = mat.array() - 100;
    std::cout << mat << '\n';
    Eigen::Vector2d vv = Eigen::Vector2d::Ones();
    // vv.setRandom();
    std::cout << "--------------" << '\n';
    vv *= 2;
    std::cout << vv << '\n';
    std::cout << mat.diagonal() << '\n';
    std::cout << vv.lpNorm<1>() << '\n';
    std::cout << vv.lpNorm<2>() << '\n';
    std::cout << vv.lpNorm<3>() << '\n';
    std::cout << vv.lpNorm<20>() << '\n';
    std::cout << mat << '\n';
    std::cout << mat.colwise().sum() << '\n';
    std::cout << mat.colwise().maxCoeff() << '\n';
    std::cout << (mat.array() > 0).all() << '\n';

    Eigen::MatrixXf::Index maxRow, maxCol;
    // std::ptrdiff_t maxRow, maxCol;
    // int maxRow, maxCol;
    float max = mat.maxCoeff(&maxRow, &maxCol);
    std::cout << maxRow << '\n';

    Eigen::MatrixXf mat2(2,4);
    mat2 <<  1, 2, 6, 9,
             3, 1, 7, 2;

    Eigen::MatrixXf::Index   maxIndex;
    float maxNorm = mat2.colwise().sum().maxCoeff(&maxIndex);

    std::cout << "Maximum sum at position " << maxIndex << std::endl;

    std::cout << "The corresponding vector is: " << std::endl;
    std::cout << mat2.col( maxIndex  ) << std::endl;
    std::cout << "And its sum is is: " << maxNorm << std::endl;
    std::cout << mat << std::endl;
    mat = mat.cwiseProduct(mat);
    std::cout << mat << std::endl;


    //==============================
    //      Maps and Mapping
    //==============================
    int array[8];
    for(int i = 0; i < 8; ++i) array[i] = i;
    std::cout << "Column-major:\n" << Eigen::Map<Eigen::Matrix<int,2,4> >(array) << '\n';
    std::cout << "Row-major:\n" << Eigen::Map<Eigen::Matrix<int,2,4,Eigen::RowMajor> >(array) << '\n';
    Eigen::Map<Eigen::Matrix<int,2,4> > fromArray(array);
    std::cout << fromArray(1,1) << std::endl;
    fromArray(1,1) = 50;
    std::cout << array[3] << std::endl;
    Eigen::VectorXd vec(5);
    std::cout << vec << std::endl;

    //==============================
    //  Placement New with Maps
    //==============================
    int data[] = {1,2,3,4,5,6,7,8,9};
    Eigen::Map<Eigen::RowVectorXi> vector(data,4);
    std::cout << "The mapped vector v is: " << vector(2) << "\n";
    Eigen::Map<Eigen::RowVectorXi>* pMap = new (&vector) Eigen::Map<Eigen::RowVectorXi>(data+4,5);
    std::cout << *pMap << std::endl;


    //==============================
    //          Ordering
    //==============================
    std::cout << mat << '\n';
    Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> M1(mat);
    Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic,Eigen::RowMajor> M2(mat);
    std::cout << "==========" << '\n';
    std::cout << M1 << '\n';
    std::cout << "==========" << '\n';
    std::cout << M2 << '\n';
    std::cout << "==========" << '\n';
    std::cout << M1.data()[0] << '\n';
    std::cout << M1.size() << '\n';


    //==============================
    //          Aliasing
    //==============================
    #define EIGEN_NO_DEBUG
    Eigen::Matrix2i a; a << 1, 2, 3, 4;
    a = a.transpose().eval(); // !!! do NOT do this !!!
    std::cout << a << '\n';



    Eigen::MatrixXf matA(2,2), matB(2,2);
    matA << 2, 0,  0, 2;
    // Simple but not quite as efficient
    matB = matA * matA;
    // More complicated but also more efficient
    matB.noalias() = matA * matA;

    std::cout << "==========" << '\n';
    Eigen::MatrixXf A(2,2), B(3,2);
    B << 2, 0,  0, 3, 1, 1;
    A << 2, 0, 0, -2;
    // A = (B * A).cwiseAbs(); WRONG!!!
    A = (B * A).eval().cwiseAbs();
    std::cout << A << '\n';


    mat_1_2x2 m1;
    mat_2_2x2 m2;

    double doubles[4]{1, 2, 3, 4};

    Eigen::Map<mat_2_2x2> m2_map(doubles);

    m1 << 1, 2, 3, 4;
    m2 = m1;

    std::cout << m2 << '\n';

    printMat(m2);
    printMat(m2_map);
}
