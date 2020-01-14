#include <gtest/gtest.h>
#include <iostream>
#include "../include/mat3.hpp"
#include "../include/mat2.hpp"

TEST(Mat3Testing, CanCreateMatrix4D)
{
    clutch::Mat3<float> test{ 1.0, 2.0, 3.0, 
                              5.5, 6.5, 7.5, 
                              9.0, 10.0,11.0};
    
    ASSERT_FLOAT_EQ(test.get(0,0),1.0);
    ASSERT_FLOAT_EQ(test.get(0,2),3.0);
    ASSERT_FLOAT_EQ(test.get(1,0),5.5);
    ASSERT_FLOAT_EQ(test.get(1,2),7.5);
    ASSERT_FLOAT_EQ(test.get(2,2),11.0);
}

TEST(Mat3Testing, CanCompareMatrix)
{
    clutch::Mat3<float> m1{1.0f, 2.0f, 3.0f,
                           5.0f, 6.0f, 7.0f, 
                           9.0f, 8.0f, 7.0f};

    clutch::Mat3<float> t1{ 1.0f, 2.0f, 3.0f,
                            5.0f, 6.0f, 7.0f, 
                            9.0f, 8.0f, 7.0f};

    clutch::Mat3<float> m2{ 1.0f, 2.0f, 3.0f,
                            5.0f, 6.0f, 7.0f, 
                            9.0f, 8.0f, 7.0f};

    clutch::Mat3<float> t2{ 2.0f, 3.0f, 4.0f,
                            6.0f, 7.0f, 8.0f, 
                            8.0f, 7.0f, 6.0f};
    ASSERT_TRUE(m1 == t1);
    ASSERT_FALSE(m2 == t2);
}

TEST(Mat3Testing, CanAddMatrix)
{
    clutch::Mat3<float> m1{ 1.0f, 2.0f, 3.0f,
                            2.0f, 4.0f, 4.0f,
                            8.0f, 6.0f, 4.0f};
                            
    clutch::Mat3<float> m2{ 1.0f, 1.0f, 1.0f, 
                            2.0f, 2.0f, 2.0f, 
                            3.0f, 3.0f, 3.0f};

    clutch::Mat3<float> m3{ 1.0f, 2.0f, 3.0f,
                            2.0f, 4.0f, 4.0f, 
                            8.0f, 6.0f, 4.0f};
    
    clutch::Mat3<float>  r{ 2.0f, 3.0f, 4.0f, 
                            4.0f, 6.0f, 6.0f,
                           11.0f, 9.0f, 7.0f};

    ASSERT_TRUE(m1 + m2  == r);
    ASSERT_TRUE((m3 += m2) == r);
}

TEST(Mat3Testing, CanAddMatrixSacalar)
{
    clutch::Mat3<float> m1{ 1.0f, 2.0f, 3.0f,
                            2.0f, 4.0f, 4.0f, 
                            8.0f, 6.0f, 4.0f};
                            
    clutch::Mat3<float>  r{ 2.0f, 3.0f, 4.0f,
                            3.0f, 5.0f, 5.0f,
                            9.0f, 7.0f, 5.0f};

    ASSERT_TRUE(m1 + 1 == r);
    ASSERT_TRUE(1 + m1 == r);
}

TEST(Mat3Testing, CanSubstractMatrix)
{
    clutch::Mat3<float> m1{ 1.0f, 2.0f, 3.0f, 
                            2.0f, 4.0f, 4.0f, 
                            8.0f, 6.0f, 4.0f};
                            
    clutch::Mat3<float> m2{ 1.0f, 1.0f, 1.0f, 
                            2.0f, 2.0f, 2.0f, 
                            3.0f, 3.0f, 3.0f};

    clutch::Mat3<float> m3{ 1.0f, 2.0f, 3.0f, 
                            2.0f, 4.0f, 4.0f,
                            8.0f, 6.0f, 4.0f};
    
    clutch::Mat3<float>  r{ 0.0f, 1.0f, 2.0f, 
                            0.0f, 2.0f, 2.0f, 
                            5.0f, 3.0f, 1.0f};
    ASSERT_TRUE(m1  - m2  == r);
    ASSERT_TRUE((m3 -= m2) == r);
}

TEST(Mat3Testing, CanSubstractMatrixScalar)
{
    clutch::Mat3<float> m1{ 1.0f, 2.0f, 3.0f, 
                            2.0f, 4.0f, 4.0f, 
                            8.0f, 6.0f, 4.0f};
                            
    clutch::Mat3<float>  r{ 0.0f, 1.0f, 2.0f,
                            1.0f, 3.0f, 3.0f,
                            7.0f, 5.0f, 3.0f};

    ASSERT_TRUE(m1 - 1 == r);
    ASSERT_TRUE(1 - m1 == r);
}

TEST(Mat3Testing, CanMultiplyMatrixScalar)
{
    clutch::Mat3<float> m1{ 1.0f, 2.0f, 3.0f, 
                            2.0f, 4.0f, 4.0f, 
                            8.0f, 6.0f, 4.0f};
                            
    clutch::Mat3<float>  r{2.0f, 4.0f, 6.0f,
                           4.0f, 8.0f, 8.0f,
                          16.0f,12.0f, 8.0f};

    ASSERT_TRUE(m1 * 2 == r);
    ASSERT_TRUE( 2 * m1 == r);
}

TEST(Mat3Testing, CanMDivideMatrixScalar)
{
    clutch::Mat3<float> m1{ 1.0f, 2.0f, 3.0f, 
                            2.0f, 4.0f, 4.0f,
                            8.0f, 6.0f, 4.0f};
                            
    clutch::Mat3<float>  r{0.5f, 1.0f, 3.0f / 2.0f,
                           1.0f, 2.0f, 2.0f,
                           4.0f, 3.0f, 2.0f};

    ASSERT_TRUE(m1 / 2 == r);
    ASSERT_TRUE(2 / m1 == r);
}

TEST(Mat3Testing, CanMultiplyMatrixVector)
{
    clutch::Mat3<float> m1{ 1.0f, 2.0f, 3.0f, 
                            2.0f, 4.0f, 4.0f, 
                            8.0f, 6.0f, 4.0f};

    clutch::Vec3<float>  v1{1.0f, 2.0f,  3.0f};
    clutch::Vec3<float>  r{14.0f, 22.0f, 32.0f};

    ASSERT_TRUE(m1 * v1 == r);
}

TEST(Mat3Testing, CanMultiplyMatrices)
{
    clutch::Mat3<float> m1{ 1.0, 2.0, 3.0, 
                            5.0, 6.0, 7.0, 
                            9.0, 8.0, 7.0};

    clutch::Mat3<float> m2{ -2.0, 1.0, 2.0, 
                             3.0, 2.0, 1.0, 
                             4.0, 3.0, 6.0};

    clutch::Mat3<float>  r{ 16.0, 14.0, 22.0,
                            36.0, 38.0, 58.0, 
                            34.0, 46.0, 68.0};
    ASSERT_TRUE(m1 * m2 == r);
    ASSERT_TRUE((m1 *= m2) == r);
}

TEST(Mat3Testing, IdentityMatrix)
{
    clutch::Mat3<float> m1{ 0.0, 1.0, 2.0,
                            1.0, 2.0, 4.0, 
                            2.0, 4.0, 8.0};

    ASSERT_TRUE(m1 * clutch::Mat3<float>{} == m1);
}

TEST(Mat3Testing, CanTranspose)
{
    clutch::Mat3<float> m1{0.0, 9.0, 3.0, 
                           9.0, 8.0, 0.0, 
                           1.0, 8.0, 5.0};

    clutch::Mat3<float>  r{0.0, 9.0, 1.0, 
                           9.0, 8.0, 8.0, 
                           3.0, 0.0, 5.0};
    ASSERT_TRUE(Transpose(m1) == r);
}


TEST(Mat3Testing, CanComputeLargeMatrixDeterminants)
{
    clutch::Mat3<float> m2{-2.0,-8.0, 3.0, 
                           -3.0, 1.0, 7.0, 
                            1.0, 2.0,-9.0};

    ASSERT_FLOAT_EQ(Determinant(m2),185.0f);
}

TEST(Mat3Testing, CanGetSubmatrix)
{
    clutch::Mat3<float> m2{-2.0,-8.0, 3.0, 
                           -3.0, 1.0, 7.0, 
                            1.0, 2.0,-9.0};

    clutch::Mat2<float> sub{1.0f,7.0f, 
                            2.0f,-9.0f};

    auto res = m2.submatrix(0,0);

    ASSERT_FLOAT_EQ(res.get(0,0), 1.0f);
    ASSERT_FLOAT_EQ(res.get(0,1), 7.0f);
    ASSERT_FLOAT_EQ(res.get(1,0), 2.0f);
    ASSERT_FLOAT_EQ(res.get(1,1),-9.0f);
}

TEST(Mat3Testing, CanCompute4DMatrixInverse)
{
    clutch::Mat3<float> m1{ 8.0f, -5.0f, 9.0f, 
                            7.0f,  5.0f, 6.0f, 
                           -6.0f,  0.0f, 9.0f};
                                
    
    auto result = clutch::Inverse(m1);

    ASSERT_FLOAT_EQ(result.get(0,0),0.040000000000000000001f);
    ASSERT_FLOAT_EQ(result.get(0,1),0.04f);
    ASSERT_FLOAT_EQ(result.get(0,2),-0.066666666666666666666f);

    ASSERT_FLOAT_EQ(result.get(1,0),-0.088f);
    ASSERT_FLOAT_EQ(result.get(1,1), 0.112f);
    ASSERT_FLOAT_EQ(result.get(1,2), 0.013333333333333333333f);

    ASSERT_FLOAT_EQ(result.get(2,0), 0.026666666666666666666f);
    ASSERT_FLOAT_EQ(result.get(2,1), 0.026666666666666666666f);
    ASSERT_FLOAT_EQ(result.get(2,2), 0.066666666666666666666f);
}
