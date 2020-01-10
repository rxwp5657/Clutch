#include <gtest/gtest.h>
#include <math.h>
#include <iostream>
#include "../include/vec2.hpp"

TEST(Vec2Testing, Vec2CanCopy)
{
    clutch::Vec2<float> test{1.0f, 2.0f};
    auto test_copy = test;

    ASSERT_TRUE(test == test_copy); 
}

TEST(Vec2Testing, Vec2CanAccesNormalMembers)
{
    clutch::Vec2<float> test{1.0f, 2.0f};
    ASSERT_FLOAT_EQ(test.x, 1.0f);
    ASSERT_FLOAT_EQ(test.y, 2.0f);
}

TEST(Vec2Testing, Vec2CanAddVector)
{   
    clutch::Vec2<float> a{1.0f, 2.0f};
    clutch::Vec2<float> b{3.0f, 1.0f};
    
    auto r = a + b;

    ASSERT_FLOAT_EQ(r.x, 4.0f);
    ASSERT_FLOAT_EQ(r.y, 3.0f);
}

TEST(Vec2Testing, Vec2CanAddVectorScalar)
{   
    clutch::Vec2<float> a{1.0f, 2.0f};
    
    auto r = a + 1;

    ASSERT_FLOAT_EQ(r.x, 2.0f);
    ASSERT_FLOAT_EQ(r.y, 3.0f);
}

TEST(Vec2Testing, Vec2CanAddMember)
{   
    clutch::Vec2<float> a{1.0f, 2.0f};
    clutch::Vec2<float> b{3.0f, 1.0f};

    a += 1.0;

    ASSERT_FLOAT_EQ(a.x, 2.0f);
    ASSERT_FLOAT_EQ(a.y, 3.0f);

    a += b;
    
    ASSERT_FLOAT_EQ(a.x, 5.0f);
    ASSERT_FLOAT_EQ(a.y, 4.0f); 
}

TEST(Vec2Testing, Vec2CanMultiplyMember)
{   
    clutch::Vec2<float> a{1.0f, 2.0f};
    clutch::Vec2<float> b{3.0f, 1.0f};

    a *= 2.0;

    ASSERT_FLOAT_EQ(a.x, 2.0f);
    ASSERT_FLOAT_EQ(a.y, 4.0f);

    a *= b;
    
    ASSERT_FLOAT_EQ(a.x, 6.0f);
    ASSERT_FLOAT_EQ(a.y, 4.0f);
}

TEST(Vec2Testing, Vec2CanSubstractMember)
{   
    clutch::Vec2<float> a{1.0f, 2.0f};
    clutch::Vec2<float> b{3.0f, 1.0f};

    a -= 2.0;

    ASSERT_FLOAT_EQ(a.x, -1.0f);
    ASSERT_FLOAT_EQ(a.y, 0.0f);

    a -= b;
    
    ASSERT_FLOAT_EQ(a.x, -4.0f);
    ASSERT_FLOAT_EQ(a.y, -1.0f);
}

TEST(Vec2Testing, Vec2CanDivideMember)
{   
    clutch::Vec2<float> a{1.0f, 2.0f};
    clutch::Vec2<float> b{3.0f, 1.0f};

    a /= 2.0;

    ASSERT_FLOAT_EQ(a.x, 0.5f);
    ASSERT_FLOAT_EQ(a.y, 1.0f);

    a /= b;
    
    ASSERT_FLOAT_EQ(a.x, 0.5f / 3.0f);
    ASSERT_FLOAT_EQ(a.y, 1.0f);
}

TEST(Vec2Testing, Vec2Substraction)
{
    clutch::Vec2<float> a{1.0f, 2.0f};
    clutch::Vec2<float> b{3.0f, 1.0f};

    auto r = a - b;

    ASSERT_FLOAT_EQ(r.x,-2.0f);
    ASSERT_FLOAT_EQ(r.y, 1.0f);
}

TEST(Vec2Testing, Vec2ScalarMultiplication)
{
    clutch::Vec2<float> a{1.0f, 2.0f};

    auto r = a * 4.0f;

    ASSERT_FLOAT_EQ(r.x, 4.0f);
    ASSERT_FLOAT_EQ(r.y, 8.0f);
}


TEST(Vec2Testing, Vec2VectorNegation){
    clutch::Vec2<float> v{1.0f, -2.0f};
    clutch::Vec2<float> r{-1.0f, 2.0f};

    ASSERT_TRUE(-v == r);
}

TEST(Vec2Testing, Vec2VectorScalarDivition){
    clutch::Vec2<float> v{1.0f, -2.0f};
    clutch::Vec2<float> r{0.5f, -1.0f};

    ASSERT_TRUE(v / 2.0f == r);
}

TEST(Vec2Testing, Vec2VectorMagnitude){
    clutch::Vec2<float> v1{1.0f, 0.0f};
    clutch::Vec2<float> v2{0.0f, 1.0f};
    clutch::Vec2<float> v3{0.0f, 0.0f};
    clutch::Vec2<float> v4{1.0f, 2.0f};
    clutch::Vec2<float> v5{-1.0f,-2.0};

    ASSERT_FLOAT_EQ(Mag(v1),1.0);
    ASSERT_FLOAT_EQ(Mag(v2),1.0);
    ASSERT_FLOAT_EQ(Mag(v3),0.0);
    ASSERT_FLOAT_EQ(Mag(v4),2.236068);
    ASSERT_FLOAT_EQ(Mag(v5),2.236068);
}

TEST(Vec2Testing, Vec2DotProduct){
    clutch::Vec2<float> v1{1.0f, 2.0f};
    clutch::Vec2<float> v2{2.0f, 3.0f};

    ASSERT_FLOAT_EQ(Dot(v1,v2),8.0);
}

TEST(Vec2Testing, Vec2Normalize){
    clutch::Vec2<float> v1{1.0f, 2.0f};

    ASSERT_FLOAT_EQ(Mag(Normalize(v1)),1.0);
}

#if defined(STORAGE_SSE)

TEST(Vec2Testing, Vec2CanAccessSSEMembers)
{
    clutch::Vec2<double> test{1.0, 2.0};
    double temp[2] __attribute__((aligned(16)));

    _mm_store_pd(&temp[0] , test.storage);
    ASSERT_FLOAT_EQ(temp[0], 1.0f);
    ASSERT_FLOAT_EQ(temp[1], 2.0f);
}

TEST(Vec2Testing, Vec2CanAddVectorSSE)
{   
    clutch::Vec2<double> a{1.0, 2.0};
    clutch::Vec2<double> b{3.0, 1.0};
    
    auto r = a + b;

    ASSERT_FLOAT_EQ(r.x, 4.0);
    ASSERT_FLOAT_EQ(r.y, 3.0);
}

TEST(Vec2Testing, Vec2CanAddVectorScalarSSE)
{   
    clutch::Vec2<double> a{1.0, 2.0};
    
    auto r = a + 1;

    ASSERT_FLOAT_EQ(r.x, 2.0);
    ASSERT_FLOAT_EQ(r.y, 3.0);
}

TEST(Vec2Testing, Vec2CanAddMemberSSE)
{   
    clutch::Vec2<double> a{1.0, 2.0};
    clutch::Vec2<double> b{3.0, 1.0};

    a += 1.0;

    ASSERT_FLOAT_EQ(a.x, 2.0);
    ASSERT_FLOAT_EQ(a.y, 3.0);

    a += b;
    
    ASSERT_FLOAT_EQ(a.x, 5.0);
    ASSERT_FLOAT_EQ(a.y, 4.0); 
}

TEST(Vec2Testing, Vec2CanMultiplyMemberSSE)
{   
    clutch::Vec2<double> a{1.0, 2.0};
    clutch::Vec2<double> b{3.0, 1.0};

    a *= 2.0;

    ASSERT_FLOAT_EQ(a.x, 2.0);
    ASSERT_FLOAT_EQ(a.y, 4.0);

    a *= b;
    
    ASSERT_FLOAT_EQ(a.x, 6.0);
    ASSERT_FLOAT_EQ(a.y, 4.0);
}

TEST(Vec2Testing, Vec2CanSubstractMemberSSE)
{   
    clutch::Vec2<double> a{1.0, 2.0};
    clutch::Vec2<double> b{3.0, 1.0};

    a -= 2.0;

    ASSERT_FLOAT_EQ(a.x, -1.0);
    ASSERT_FLOAT_EQ(a.y, 0.0);

    a -= b;
    
    ASSERT_FLOAT_EQ(a.x, -4.0);
    ASSERT_FLOAT_EQ(a.y, -1.0);
}

TEST(Vec2Testing, Vec2CanDivideMemberSSE)
{   
    clutch::Vec2<double> a{1.0, 2.0};
    clutch::Vec2<double> b{3.0, 1.0};

    a /= 2.0;

    ASSERT_FLOAT_EQ(a.x, 0.5);
    ASSERT_FLOAT_EQ(a.y, 1.0);

    a /= b;
    
    ASSERT_FLOAT_EQ(a.x, 0.5 / 3.0);
    ASSERT_FLOAT_EQ(a.y, 1.0);
}

TEST(Vec2Testing, Vec2SubstractionSSE)
{
    clutch::Vec2<double> a{1.0, 2.0};
    clutch::Vec2<double> b{3.0, 1.0};

    auto r = a - b;

    ASSERT_FLOAT_EQ(r.x,-2.0);
    ASSERT_FLOAT_EQ(r.y, 1.0);
}

TEST(Vec2Testing, Vec2ScalarMultiplicationSSE)
{
    clutch::Vec2<double> a{1.0, 2.0};

    auto r = a * 4.0f;

    ASSERT_FLOAT_EQ(r.x, 4.0);
    ASSERT_FLOAT_EQ(r.y, 8.0);
}


TEST(Vec2Testing, Vec2VectorNegationSSE){
    
    clutch::Vec2<double> v{1.0, -2.0};
    
    auto res = -v;

    ASSERT_FLOAT_EQ(res.x, -1.0);
    ASSERT_FLOAT_EQ(res.y,  2.0);
}

TEST(Vec2Testing, Vec2VectorScalarDivitionSSE){
    clutch::Vec2<double> v{1.0, -2.0};

    auto r = v / 2.0;

    ASSERT_FLOAT_EQ(r.x, 0.5);
    ASSERT_FLOAT_EQ(r.y,-1.0);
}

TEST(Vec2Testing, Vec2VectorMagnitudeSSE){
    clutch::Vec2<double> v1{1.0, 0.0};
    clutch::Vec2<double> v2{0.0, 1.0};
    clutch::Vec2<double> v3{0.0, 0.0};
    clutch::Vec2<double> v4{1.0, 2.0};
    clutch::Vec2<double> v5{-1.0,-2.0};

    ASSERT_FLOAT_EQ(Mag(v1),1.0);
    ASSERT_FLOAT_EQ(Mag(v2),1.0);
    ASSERT_FLOAT_EQ(Mag(v3),0.0);
    ASSERT_FLOAT_EQ(Mag(v4),2.236068);
    ASSERT_FLOAT_EQ(Mag(v5),2.236068);
}

TEST(Vec2Testing, Vec2DotProductSSE){
    clutch::Vec2<double> v1{1.0f, 2.0f};
    clutch::Vec2<double> v2{2.0f, 3.0f};

    ASSERT_FLOAT_EQ(Dot(v1,v2),8.0);
}

TEST(Vec2Testing, Vec2NormalizeSSE){
    clutch::Vec2<double> v1{1.0, 2.0};

    ASSERT_FLOAT_EQ(Mag(Normalize(v1)),1.0);
}

#endif // SIMD Tests