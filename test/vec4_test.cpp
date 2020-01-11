#include <gtest/gtest.h>
#include <math.h>
#include <iostream>
#include "../include/vec4.hpp"

TEST(Vec4Testing, CanCopyGeneric)
{
    clutch::Vec4<float> test{1.0f, 2.0f, 3.0f, 4.0f};
    auto test_copy = test;

    ASSERT_TRUE(test == test_copy); 
}

TEST(Vec4Testing, CanAccesNormalMembersGeneric)
{
    clutch::Vec4<float> test{1.0f, 2.0f, 3.0f, 4.0f};
    ASSERT_FLOAT_EQ(test.x, 1.0f);
    ASSERT_FLOAT_EQ(test.y, 2.0f);
    ASSERT_FLOAT_EQ(test.z, 3.0f);
    ASSERT_FLOAT_EQ(test.w, 4.0f);
    ASSERT_FLOAT_EQ(test.r, 1.0f);
    ASSERT_FLOAT_EQ(test.g, 2.0f);
    ASSERT_FLOAT_EQ(test.b, 3.0f);
    ASSERT_FLOAT_EQ(test.a, 4.0f);
}

TEST(Vec4Testing, CanAddVectorGeneric)
{   
    clutch::Vec4<float> a{1.0f, 2.0f, 3.0f, 4.0f};
    clutch::Vec4<float> b{3.0f, 1.0f, 1.0f, 2.0f};
    
    auto r = a + b;

    ASSERT_FLOAT_EQ(r.x, 4.0f);
    ASSERT_FLOAT_EQ(r.y, 3.0f);
    ASSERT_FLOAT_EQ(r.z, 4.0f);
    ASSERT_FLOAT_EQ(r.w, 6.0f);
}

TEST(Vec4Testing, CanAddVectorScalarGeneric)
{   
    clutch::Vec4<float> a{1.0f, 2.0f, 3.0f, 4.0f};
    
    auto r = a + 1;

    ASSERT_FLOAT_EQ(r.x, 2.0f);
    ASSERT_FLOAT_EQ(r.y, 3.0f);
    ASSERT_FLOAT_EQ(r.z, 4.0f);
    ASSERT_FLOAT_EQ(r.w, 5.0f);
}

TEST(Vec4Testing, CanAddMemberGeneric)
{   
    clutch::Vec4<float> a{1.0f, 2.0f, 3.0f, 4.0f};
    clutch::Vec4<float> b{3.0f, 1.0f, 1.0f, 2.0f};

    a += 1.0;

    ASSERT_FLOAT_EQ(a.x, 2.0f);
    ASSERT_FLOAT_EQ(a.y, 3.0f);
    ASSERT_FLOAT_EQ(a.z, 4.0f);
    ASSERT_FLOAT_EQ(a.w, 5.0f);

    a += b;
    
    ASSERT_FLOAT_EQ(a.x, 5.0f);
    ASSERT_FLOAT_EQ(a.y, 4.0f);
    ASSERT_FLOAT_EQ(a.z, 5.0f);
    ASSERT_FLOAT_EQ(a.w, 7.0f); 
}

TEST(Vec4Testing, CanMultiplyMemberGeneric)
{   
    clutch::Vec4<float> a{1.0f, 2.0f, 3.0f, 4.0f};
    clutch::Vec4<float> b{3.0f, 1.0f, 1.0f, 2.0f};

    a *= 2.0;

    ASSERT_FLOAT_EQ(a.x, 2.0f);
    ASSERT_FLOAT_EQ(a.y, 4.0f);
    ASSERT_FLOAT_EQ(a.z, 6.0f);
    ASSERT_FLOAT_EQ(a.w, 8.0f);

    a *= b;
    
    ASSERT_FLOAT_EQ(a.x, 6.0f);
    ASSERT_FLOAT_EQ(a.y, 4.0f);
    ASSERT_FLOAT_EQ(a.z, 6.0f);
    ASSERT_FLOAT_EQ(a.w, 16.0f); 
}

TEST(Vec4Testing, CanSubstractMemberGeneric)
{   
    clutch::Vec4<float> a{1.0f, 2.0f, 3.0f, 4.0f};
    clutch::Vec4<float> b{3.0f, 1.0f, 1.0f, 2.0f};

    a -= 2.0;

    ASSERT_FLOAT_EQ(a.x, -1.0f);
    ASSERT_FLOAT_EQ(a.y, 0.0f);
    ASSERT_FLOAT_EQ(a.z, 1.0f);
    ASSERT_FLOAT_EQ(a.w, 2.0f);

    a -= b;
    
    ASSERT_FLOAT_EQ(a.x, -4.0f);
    ASSERT_FLOAT_EQ(a.y, -1.0f);
    ASSERT_FLOAT_EQ(a.z,  0.0f);
    ASSERT_FLOAT_EQ(a.w,  0.0f);
}

TEST(Vec4Testing, CanDivideMemberGeneric)
{   
    clutch::Vec4<float> a{1.0f, 2.0f, 3.0f, 3.0f};
    clutch::Vec4<float> b{3.0f, 1.0f, 1.0f, 1.0f};

    a /= 2.0;

    ASSERT_FLOAT_EQ(a.x, 0.5f);
    ASSERT_FLOAT_EQ(a.y, 1.0f);
    ASSERT_FLOAT_EQ(a.z, 3.0f/2.0f);
    ASSERT_FLOAT_EQ(a.w, 3.0f/2.0f);

    a /= b;
    
    ASSERT_FLOAT_EQ(a.x, 0.5f / 3.0f);
    ASSERT_FLOAT_EQ(a.y, 1.0f);
    ASSERT_FLOAT_EQ(a.z, 3.0f/2.0f);
    ASSERT_FLOAT_EQ(a.w, 3.0f/2.0f);
}

TEST(Vec4Testing, SubstractionGeneric)
{
    clutch::Vec4<float> a{1.0f, 2.0f, 3.0f, 1.0f};
    clutch::Vec4<float> b{3.0f, 1.0f, 1.0f, 1.0f};

    auto r = a - b;

    ASSERT_FLOAT_EQ(r.x,-2.0f);
    ASSERT_FLOAT_EQ(r.y, 1.0f);
    ASSERT_FLOAT_EQ(r.z, 2.0f);
    ASSERT_FLOAT_EQ(r.w, 0.0f);
}

TEST(Vec4Testing, ScalarMultiplicationGeneric)
{
    clutch::Vec4<float> a{1.0f, 2.0f, 3.0f, 2.0f};

    auto r = a * 4.0f;

    ASSERT_FLOAT_EQ(r.x, 4.0f);
    ASSERT_FLOAT_EQ(r.y, 8.0f);
    ASSERT_FLOAT_EQ(r.z, 12.0f);
    ASSERT_FLOAT_EQ(r.w, 8.0f);
}

TEST(Vector4Testing, VectorNegationGeneric)
{
    clutch::Vec4<float> v{1.0f, -2.0f, 3.0f, 1.0f};
    clutch::Vec4<float> r{-1.0f, 2.0f,-3.0f,-1.0f};

    ASSERT_TRUE(-v == r);
}

TEST(Vector4Testing, VectorScalarDivitionGeneric)
{
    clutch::Vec4<float> v{1.0f, -2.0f, 3.0f, 6.0f};
    clutch::Vec4<float> r{0.5f, -1.0f, 1.5f, 3.0f};

    ASSERT_TRUE(v / 2.0f == r);
}

TEST(Vector4Testing, VectorMagnitudeGeneric)
{
    clutch::Vec4<float> v1{1.0f, 0.0f, 0.0f, 0.0f};
    clutch::Vec4<float> v2{0.0f, 1.0f, 0.0f, 0.0f};
    clutch::Vec4<float> v3{0.0f, 0.0f, 1.0f, 0.0f};
    clutch::Vec4<float> v4{1.0f, 2.0f, 3.0f, 4.0f};
    clutch::Vec4<float> v5{-1.0f,-2.0,-3.0f,-4.0f};

    ASSERT_FLOAT_EQ(Mag(v1),1.0);
    ASSERT_FLOAT_EQ(Mag(v2),1.0);
    ASSERT_FLOAT_EQ(Mag(v3),1.0);
    ASSERT_FLOAT_EQ(Mag(v4),5.4772258);
    ASSERT_FLOAT_EQ(Mag(v5),5.4772258);
}

TEST(Vector4Testing, DotProductGeneric)
{
    clutch::Vec4<float> v1{1.0f, 2.0f, 3.0f, 1.0f};
    clutch::Vec4<float> v2{2.0f, 3.0f, 4.0f, 1.0f};

    ASSERT_FLOAT_EQ(Dot(v1,v2),21.0);
}

#if defined(STORAGE_SSE)

TEST(Vector4Testing, CrossProduct){
    clutch::Vec4<float> v1{ 1.0, 2.0, 3.0, 0.0f};
    clutch::Vec4<float> v2{ 2.0, 3.0, 4.0, 0.0f};
    clutch::Vec4<float> v3{ 1.0, 2.0,-2.0, 0.0f};
    clutch::Vec4<float> v4{ 3.0, 0.0, 1.0, 0.0f};
    clutch::Vec4<float> r1{-1.0, 2.0,-1.0, 0.0f};
    clutch::Vec4<float> r2{ 1.0,-2.0, 1.0, 0.0f};
    clutch::Vec4<float> r3{ 2.0,-7.0,-6.0, 0.0f};
    
    ASSERT_TRUE(Cross(v1,v2) == r1);
    ASSERT_TRUE(Cross(v2,v1) == r2);
    ASSERT_TRUE(Cross(v3,v4) == r3);
}

#endif

TEST(Vector4Testing, Vec4NormalizeGeneric)
{
    clutch::Vec4<float> v1{1.0f, 2.0f, 3.0f, 8.0};

    ASSERT_FLOAT_EQ(Mag(Normalize(v1)), 1.0);
}