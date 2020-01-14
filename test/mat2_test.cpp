#include <gtest/gtest.h>
#include <iostream>
#include "../include/mat2.hpp"

TEST(Matrix2DTesting, CanCreateMatrix2D)
{
    clutch::Mat2<float> test{ 1.0f, 2.0f, 
                              13.5f,14.5f};
    
    ASSERT_FLOAT_EQ(test.get(0,0),1.0);
    ASSERT_FLOAT_EQ(test.get(0,1),2.0);
    ASSERT_FLOAT_EQ(test.get(1,0),13.5);
    ASSERT_FLOAT_EQ(test.get(1,1),14.5);
}

TEST(Matrix2DTesting, CanCompareMatrix2D)
{
    clutch::Mat2<float> m1{1.0f, 2.0f,
                           5.0f, 6.0f};

    clutch::Mat2<float> t1{1.0f, 2.0f,
                           5.0f, 6.0f};

    ASSERT_TRUE(m1 == t1);
}

TEST(Mat2Testing, CanAddMatrix)
{
    clutch::Mat2<float> m1{ 1.0f, 2.0f, 
                            2.0f, 4.0f};
                            
    clutch::Mat2<float> m2{ 1.0f, 1.0f, 
                            2.0f, 2.0f};

    clutch::Mat2<float> m3{ 1.0f, 2.0f, 
                            2.0f, 4.0f};
    
    clutch::Mat2<float>  r{ 2.0f, 3.0f,
                            4.0f, 6.0f};
    
    ASSERT_TRUE(m1 + m2  == r);
    ASSERT_TRUE((m3 += m2) == r);
}

TEST(Mat2Testing, CanAddMatrixSacalar)
{
    clutch::Mat2<float> m1{ 1.0f, 2.0f, 
                            3.0f, 4.0f};
                            
    clutch::Mat2<float>  r{ 2.0f, 3.0f, 
                            4.0f, 5.0f};

    ASSERT_TRUE(m1 + 1 == r);
    ASSERT_TRUE(1 + m1 == r);
}

TEST(Mat2Testing, CanSubstractMatrix)
{
    clutch::Mat2<float> m1{ 1.0f, 2.0f, 
                            3.0f, 4.0f};
                            
    clutch::Mat2<float> m2{ 1.0f, 1.0f, 
                            1.0f, 1.0f};

    clutch::Mat2<float> m3{ 1.0f, 2.0f, 
                            3.0f, 4.0f};
    
    clutch::Mat2<float>  r{ 0.0f, 1.0f, 
                            2.0f, 3.0f};

    ASSERT_TRUE(m1  - m2  == r);
    ASSERT_TRUE((m3 -= m2) == r);
}

TEST(Mat2Testing, CanSubstractMatrixScalar)
{
    clutch::Mat2<float> m1{ 1.0f, 2.0f, 
                            3.0f, 4.0f};
                            
    clutch::Mat2<float>  r{ 0.0f, 1.0f, 
                            2.0f, 3.0f};

    ASSERT_TRUE(m1 - 1 == r);
    ASSERT_TRUE(1 - m1 == r);
}

TEST(Mat2Testing, CanMultiplyMatrixScalar)
{
    clutch::Mat2<float> m1{ 1.0f, 2.0f, 
                            3.0f, 4.0f};
                            
    clutch::Mat2<float>  r{2.0f, 4.0f, 
                           6.0f, 8.0f};

    ASSERT_TRUE(m1 * 2 == r);
    ASSERT_TRUE( 2 * m1 == r);
}

TEST(Mat2Testing, CanMDivideMatrixScalar)
{
    clutch::Mat2<float> m1{ 1.0f, 2.0f, 3.0f, 4.0f};
                            
    clutch::Mat2<float>  r{0.5f, 1.0f, 
                           3.0f / 2.0f, 2.0f};

    ASSERT_TRUE(m1 / 2 == r);
    ASSERT_TRUE(2 / m1 == r);
}

TEST(Matrix2DTesting, CanMultiplyMatrixVector2D)
{
    clutch::Mat2<float> m1{4.0f, 2.0f, 
                           1.0f, 1.0f};

    clutch::Vec2<float>  v1{1.0f, 2.0f};
    clutch::Vec2<float>  r{8.0f, 3.0f};

    ASSERT_TRUE(m1 * v1 == r);
}

TEST(Matrix2DTesting, CanMultiplyMatrices2D)
{
    clutch::Mat2<float> m1{ 1.0f, 5.0f, 
                            6.0f, 2.0f};
                            
    clutch::Mat2<float> m2{-2.0f, 3.0f,
                            3.0f,-8.0f};

    clutch::Mat2<float>  r{ 13.0f,-37.0f, 
                           -6.0f, 2.0f};

    auto res = m1 * m2;

    ASSERT_FLOAT_EQ(res.get(0,0), 13.0f);
    ASSERT_FLOAT_EQ(res.get(0,1),-37.0f);
    ASSERT_FLOAT_EQ(res.get(1,0),-6.0f);
    ASSERT_FLOAT_EQ(res.get(1,1), 2.0f);

    ASSERT_TRUE((m1 *= m2) == r);
}


TEST(Matrix2DTesting, IdentityMatrix2D)
{
    clutch::Mat2<float> m1{4.0f, 8.0f, 
                           16.0f,32.0f};

    ASSERT_TRUE(m1 * clutch::Mat2<float>{} == m1);
}

TEST(Matrix2DTesting, CanTranspose2D)
{
    clutch::Mat2<float> m1{0.0, 0.0, 
                           5.0, 8.0};

    clutch::Mat2<float>  r{0.0f, 5.0f,
                           0.0f, 8.0f};
    ASSERT_TRUE(Transpose(m1) == r);
}


TEST(Matrix2DTesting, CanComputeLargeMatrixDeterminants2D)
{
    clutch::Mat2<float> m2{-2.0,-3.0,
                            6.0,-9.0};

    ASSERT_FLOAT_EQ(Determinant(m2),36);
}

TEST(Matrix2DTesting, CanComputeMatrixInverse2D)
{
    clutch::Mat2<float> m1{ 8.0f, 7.0f,
                           -6.0f,-3.0f};

    clutch::Mat2<float> inv1{-0.16666666666666666666f, -0.3888888888888888888f,
                              0.33333333333333333333f,  0.44444444444444444444f}; 

    auto res = clutch::Inverse(m1);

    ASSERT_FLOAT_EQ(res.get(0,0),-0.16666666666666666666f);
    ASSERT_FLOAT_EQ(res.get(0,1),-0.3888888888888888888f);
    ASSERT_FLOAT_EQ(res.get(1,0), 0.33333333333333333333f);
    ASSERT_FLOAT_EQ(res.get(1,1), 0.44444444444444444444f);
}

TEST(Matrix2DTesting, CanTranspose2DSSE)
{
    clutch::Mat2<double> m1{ 1.0, 2.0, 
                             5.0, 8.0};

    clutch::Mat2<double> r{ 1.0f, 5.0f,
                            2.0f, 8.0f};
    
    auto res = clutch::Transpose(m1);

    ASSERT_FLOAT_EQ(res.get(0,0), 1.0f);
    ASSERT_FLOAT_EQ(res.get(0,1), 5.0f);
    ASSERT_FLOAT_EQ(res.get(1,0), 2.0f);
    ASSERT_FLOAT_EQ(res.get(1,1), 8.0f);
}


TEST(Matrix2DTesting, CanMultiplyMatrixVector2DSSE)
{
    clutch::Mat2<double> m1{4.0, 2.0, 
                            1.0, 1.0};

    clutch::Vec2<double>  v1{1.0, 2.0};
    clutch::Vec2<double>  r{8.0, 3.0};

    auto result = m1 * v1;

    ASSERT_FLOAT_EQ(result.x, r.x);
    ASSERT_FLOAT_EQ(result.y, r.y);

}

TEST(Matrix2DTesting, CanMultiplyMatrices2DSSE)
{
    clutch::Mat2<double> m1{1.0, 5.0, 
                            6.0, 2.0};
                            
    clutch::Mat2<double> m2{-2.0, 3.0,
                            3.0,-8.0};

    clutch::Mat2<double>  r{ 13.0,-37.0, 
                           -6.0, 2.0};

    auto res = m1 * m2;
    
    ASSERT_FLOAT_EQ(res.get(0,0), 13.0f);
    ASSERT_FLOAT_EQ(res.get(0,1),-37.0f);
    ASSERT_FLOAT_EQ(res.get(1,0),-6.0f);
    ASSERT_FLOAT_EQ(res.get(1,1), 2.0f);
}