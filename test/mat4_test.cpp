#include <gtest/gtest.h>
#include <iostream>
#include "../include/mat4.hpp"

TEST(Mat4Testing, CanCreateMatrix4D)
{
    clutch::Mat4<float> test{ 1.0, 2.0,  3.0,  4.0, 
                              5.5, 6.5,  7.5,  8.5, 
                              9.0, 10.0, 11.0, 12.0, 
                              13.5,14.5, 15.5, 16.5};
    
    ASSERT_FLOAT_EQ(test.get(0,0),1.0);
    ASSERT_FLOAT_EQ(test.get(0,3),4.0);
    ASSERT_FLOAT_EQ(test.get(1,0),5.5);
    ASSERT_FLOAT_EQ(test.get(1,2),7.5);
    ASSERT_FLOAT_EQ(test.get(2,2),11.0);
    ASSERT_FLOAT_EQ(test.get(3,0),13.5);
    ASSERT_FLOAT_EQ(test.get(3,2),15.5);
}

TEST(Mat4Testing, CanCompareMatrix)
{
    clutch::Mat4<float> m1{1.0f, 2.0f, 3.0f, 4.0f,
                           5.0f, 6.0f, 7.0f, 8.0f, 
                           9.0f, 8.0f, 7.0f, 6.0f, 
                           5.0f, 4.0f, 5.0f, 2.0f};

    clutch::Mat4<float> t1{ 1.0f, 2.0f, 3.0f, 4.0f,
                            5.0f, 6.0f, 7.0f, 8.0f, 
                            9.0f, 8.0f, 7.0f, 6.0f, 
                            5.0f, 4.0f, 5.0f, 2.0f};

    clutch::Mat4<float> m2{ 1.0f, 2.0f, 3.0f, 4.0f,
                            5.0f, 6.0f, 7.0f, 8.0f, 
                            9.0f, 8.0f, 7.0f, 6.0f, 
                            5.0f, 4.0f, 5.0f, 2.0f};

    clutch::Mat4<float> t2{ 2.0f, 3.0f, 4.0f, 5.0f,
                            6.0f, 7.0f, 8.0f, 9.0f, 
                            8.0f, 7.0f, 6.0f, 5.0f, 
                            4.0f, 3.0f, 2.0f, 1.0f};
    ASSERT_TRUE(m1 == t1);
    ASSERT_FALSE(m2 == t2);
}

TEST(Mat4Testing, CanAddMatrix)
{
    clutch::Mat4<float> m1{ 1.0f, 2.0f, 3.0f, 4.0f, 
                            2.0f, 4.0f, 4.0f, 2.0f, 
                            8.0f, 6.0f, 4.0f, 1.0f,
                            0.0f, 0.0f, 0.0f, 1.0f};
                            
    clutch::Mat4<float> m2{ 1.0f, 1.0f, 1.0f, 1.0f, 
                            2.0f, 2.0f, 2.0f, 2.0f, 
                            3.0f, 3.0f, 3.0f, 3.0f,
                            4.0f, 4.0f, 4.0f, 0.0f};

    clutch::Mat4<float> m3{ 1.0f, 2.0f, 3.0f, 4.0f, 
                            2.0f, 4.0f, 4.0f, 2.0f, 
                            8.0f, 6.0f, 4.0f, 1.0f,
                            0.0f, 0.0f, 0.0f, 1.0f};
    
    clutch::Mat4<float>  r{ 2.0f, 3.0f, 4.0f, 5.0f, 
                            4.0f, 6.0f, 6.0f, 4.0f, 
                           11.0f, 9.0f, 7.0f, 4.0f,
                            4.0f, 4.0f, 4.0f, 1.0f};
    ASSERT_TRUE(m1 + m2  == r);
    ASSERT_TRUE((m3 += m2) == r);
}

TEST(Mat4Testing, CanAddMatrixSacalar)
{
    clutch::Mat4<float> m1{ 1.0f, 2.0f, 3.0f, 4.0f, 
                            2.0f, 4.0f, 4.0f, 2.0f, 
                            8.0f, 6.0f, 4.0f, 1.0f,
                            0.0f, 0.0f, 0.0f, 1.0f};
                            
    clutch::Mat4<float>  r{ 2.0f, 3.0f, 4.0f, 5.0f,
                            3.0f, 5.0f, 5.0f, 3.0f,
                            9.0f, 7.0f, 5.0f, 2.0f,
                            1.0f, 1.0f, 1.0f, 2.0f};

    ASSERT_TRUE(m1 + 1 == r);
    ASSERT_TRUE(1 + m1 == r);
}

TEST(Mat4Testing, CanSubstractMatrix)
{
    clutch::Mat4<float> m1{ 1.0f, 2.0f, 3.0f, 4.0f, 
                            2.0f, 4.0f, 4.0f, 2.0f, 
                            8.0f, 6.0f, 4.0f, 1.0f,
                            0.0f, 0.0f, 0.0f, 1.0f};
                            
    clutch::Mat4<float> m2{ 1.0f, 1.0f, 1.0f, 1.0f, 
                            2.0f, 2.0f, 2.0f, 2.0f, 
                            3.0f, 3.0f, 3.0f, 3.0f,
                            4.0f, 4.0f, 4.0f, 0.0f};

    clutch::Mat4<float> m3{ 1.0f, 2.0f, 3.0f, 4.0f, 
                            2.0f, 4.0f, 4.0f, 2.0f, 
                            8.0f, 6.0f, 4.0f, 1.0f,
                            0.0f, 0.0f, 0.0f, 1.0f};
    
    clutch::Mat4<float>  r{ 0.0f, 1.0f, 2.0f, 3.0f, 
                            0.0f, 2.0f, 2.0f, 0.0f, 
                            5.0f, 3.0f, 1.0f,-2.0f,
                           -4.0f,-4.0f,-4.0f, 1.0f};
    ASSERT_TRUE(m1  - m2  == r);
    ASSERT_TRUE((m3 -= m2) == r);
}

TEST(Mat4Testing, CanSubstractMatrixScalar)
{
    clutch::Mat4<float> m1{ 1.0f, 2.0f, 3.0f, 4.0f, 
                            2.0f, 4.0f, 4.0f, 2.0f, 
                            8.0f, 6.0f, 4.0f, 1.0f,
                            0.0f, 0.0f, 0.0f, 1.0f};
                            
    clutch::Mat4<float>  r{ 0.0f, 1.0f, 2.0f, 3.0f,
                            1.0f, 3.0f, 3.0f, 1.0f,
                            7.0f, 5.0f, 3.0f, 0.0f,
                           -1.0f,-1.0f,-1.0f, 0.0f};

    ASSERT_TRUE(m1 - 1 == r);
    ASSERT_TRUE(1 - m1 == r);
}

TEST(Mat4Testing, CanMultiplyMatrixScalar)
{
    clutch::Mat4<float> m1{ 1.0f, 2.0f, 3.0f, 4.0f, 
                            2.0f, 4.0f, 4.0f, 2.0f, 
                            8.0f, 6.0f, 4.0f, 1.0f,
                            0.0f, 0.0f, 0.0f, 1.0f};
                            
    clutch::Mat4<float>  r{2.0f, 4.0f, 6.0f, 8.0f,
                           4.0f, 8.0f, 8.0f, 4.0f,
                          16.0f,12.0f, 8.0f, 2.0f,
                           0.0f, 0.0f, 0.0f, 2.0f};

    ASSERT_TRUE(m1 * 2 == r);
    ASSERT_TRUE( 2 * m1 == r);
}

TEST(Mat4Testing, CanMDivideMatrixScalar)
{
    clutch::Mat4<float> m1{ 1.0f, 2.0f, 3.0f, 4.0f, 
                            2.0f, 4.0f, 4.0f, 2.0f, 
                            8.0f, 6.0f, 4.0f, 1.0f,
                            0.0f, 0.0f, 0.0f, 1.0f};
                            
    clutch::Mat4<float>  r{0.5f, 1.0f, 3.0f / 2.0f, 2.0f,
                           1.0f, 2.0f, 2.0f, 1.0f,
                           4.0f, 3.0f, 2.0f, 0.5f,
                           0.0f, 0.0f, 0.0f, 0.5f};

    ASSERT_TRUE(m1 / 2 == r);
    ASSERT_TRUE(2 / m1 == r);
}

TEST(Mat4Testing, CanMultiplyMatrixVector)
{
    clutch::Mat4<float> m1{ 1.0f, 2.0f, 3.0f, 4.0f, 
                            2.0f, 4.0f, 4.0f, 2.0f, 
                            8.0f, 6.0f, 4.0f, 1.0f,
                            0.0f, 0.0f, 0.0f, 1.0f};

    clutch::Vec4<float>  v1{1.0f, 2.0f,  3.0f, 0.0f};
    clutch::Vec4<float>  r{14.0f, 22.0f, 32.0f,0.0f};

    ASSERT_TRUE(m1 * v1 == r);
}

TEST(Mat4Testing, CanMultiplyMatrices)
{
    clutch::Mat4<float> m1{ 1.0, 2.0, 3.0, 4.0, 
                            5.0, 6.0, 7.0, 8.0, 
                            9.0, 8.0, 7.0, 6.0,
                            5.0, 4.0, 3.0, 2.0};

    clutch::Mat4<float> m2{ -2.0, 1.0, 2.0, 3.0, 
                             3.0, 2.0, 1.0,-1.0, 
                             4.0, 3.0, 6.0, 5.0, 
                             1.0, 2.0, 7.0, 8.0};

    clutch::Mat4<float>  r{ 20.0, 22.0, 50.0, 48.0, 
                            44.0, 54.0, 114.0,108.0, 
                            40.0, 58.0, 110.0,102.0, 
                            16.0, 26.0, 46.0, 42.0};
    ASSERT_TRUE(m1 * m2 == r);
    ASSERT_TRUE((m1 *= m2) == r);
}

TEST(Mat4Testing, IdentityMatrix)
{
    clutch::Mat4<float> m1{ 0.0, 1.0, 2.0, 4.0,
                            1.0, 2.0, 4.0, 8.0, 
                            2.0, 4.0, 8.0, 16.0, 
                            4.0, 8.0, 16.0, 32.0};

    ASSERT_TRUE(m1 * clutch::Mat4<float>{} == m1);
}

TEST(Mat4Testing, CanTranspose)
{
    clutch::Mat4<float> m1{0.0, 9.0, 3.0, 0.0, 
                           9.0, 8.0, 0.0, 8.0, 
                           1.0, 8.0, 5.0, 3.0, 
                           0.0, 0.0, 5.0, 8.0};

    clutch::Mat4<float>  r{0.0, 9.0, 1.0, 0.0, 
                           9.0, 8.0, 8.0, 0.0, 
                           3.0, 0.0, 5.0, 5.0,
                           0.0, 8.0, 3.0, 8.0};
    ASSERT_TRUE(Transpose(m1) == r);
}


TEST(Mat4Testing, CanComputeLargeMatrixDeterminants)
{
    clutch::Mat4<float> m2{-2.0,-8.0, 3.0, 5.0, 
                           -3.0, 1.0, 7.0, 3.0, 
                            1.0, 2.0,-9.0, 6.0, 
                           -6.0, 7.0, 7.0,-9.0};

    ASSERT_FLOAT_EQ(Determinant(m2),-4071.0);
}


TEST(Mat4Testing, CanCompute4DMatrixInverse)
{
    clutch::Mat4<float> m1{ 8.0f, -5.0f, 9.0f, 2.0f, 
                            7.0f,  5.0f, 6.0f, 1.0f, 
                           -6.0f,  0.0f, 9.0f, 6.0f,
                           -3.0f,  0.0f,-9.0f,-4.0f};
                                
    clutch::Mat4<float> inv1{-0.153846f, -0.153846f, -0.282051f, -0.538462f, 
                             -0.0769231f, 0.123077f,  0.025641f, 0.0307692f, 
                              0.358974f,  0.358974f,  0.435897f, 0.923077f, 
                             -0.692308f, -0.692308f, -0.769231f, -1.92308f}; 
    
    auto result = clutch::Inverse(m1);

    ASSERT_FLOAT_EQ(result.get(0,0),-0.15384616f);
    ASSERT_FLOAT_EQ(result.get(0,1),-0.15384616f);
    ASSERT_FLOAT_EQ(result.get(0,2),-0.2820513f);
    ASSERT_FLOAT_EQ(result.get(0,3),-0.53846157f);

    ASSERT_FLOAT_EQ(result.get(1,0),-0.076923087f);
    ASSERT_FLOAT_EQ(result.get(1,1), 0.12307693f);
    ASSERT_FLOAT_EQ(result.get(1,2), 0.025641026f);
    ASSERT_FLOAT_EQ(result.get(1,3), 0.030769225f);

    ASSERT_FLOAT_EQ(result.get(2,0), 0.35897437f);
    ASSERT_FLOAT_EQ(result.get(2,1), 0.35897437f);
    ASSERT_FLOAT_EQ(result.get(2,2), 0.43589747f);
    ASSERT_FLOAT_EQ(result.get(2,3), 0.92307699f);

    ASSERT_FLOAT_EQ(result.get(3,0),-0.69230771f);
    ASSERT_FLOAT_EQ(result.get(3,1),-0.69230771f);
    ASSERT_FLOAT_EQ(result.get(3,2),-0.76923084f);
    ASSERT_FLOAT_EQ(result.get(3,3),-1.9230771f);
}
