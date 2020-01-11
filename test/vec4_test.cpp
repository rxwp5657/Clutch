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
/*
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
*/

TEST(Vector4Testing, Vec4NormalizeGeneric)
{
    clutch::Vec4<float> v1{1.0f, 2.0f, 3.0f, 8.0};

    ASSERT_FLOAT_EQ(Mag(Normalize(v1)), 1.0);
}

// Float test

TEST(Vec4Testing, CanCopySSEInt)
{
    clutch::Vec4<int> test{1, 2, 3, 4};
    auto test_copy = test;

    ASSERT_TRUE(test == test_copy); 
}

TEST(Vec4Testing, CanAccesNormalMembersSSEInt)
{
    clutch::Vec4<int> test{1, 2, 3, 4};
    ASSERT_FLOAT_EQ(test.x, 1);
    ASSERT_FLOAT_EQ(test.y, 2);
    ASSERT_FLOAT_EQ(test.z, 3);
    ASSERT_FLOAT_EQ(test.w, 4);
    ASSERT_FLOAT_EQ(test.r, 1);
    ASSERT_FLOAT_EQ(test.g, 2);
    ASSERT_FLOAT_EQ(test.b, 3);
    ASSERT_FLOAT_EQ(test.a, 4);
}

TEST(Vec4Testing, CanAddVectorSSEInt)
{   
    clutch::Vec4<int> a{1, 2, 3, 4};
    clutch::Vec4<int> b{3, 1, 1, 2};
    
    auto r = a + b;

    ASSERT_FLOAT_EQ(r.x, 4);
    ASSERT_FLOAT_EQ(r.y, 3);
    ASSERT_FLOAT_EQ(r.z, 4);
    ASSERT_FLOAT_EQ(r.w, 6);
}

TEST(Vec4Testing, CanAddVectorScalarSSEInt)
{   
    clutch::Vec4<int> a{1, 2, 3, 4};
    
    auto r = a + 1;

    ASSERT_FLOAT_EQ(r.x, 2);
    ASSERT_FLOAT_EQ(r.y, 3);
    ASSERT_FLOAT_EQ(r.z, 4);
    ASSERT_FLOAT_EQ(r.w, 5);
}

TEST(Vec4Testing, CanAddMemberSSEInt)
{   
    clutch::Vec4<int> a{1, 2, 3, 4};
    clutch::Vec4<int> b{3, 1, 1, 2};

    a += 1.0;

    ASSERT_FLOAT_EQ(a.x, 2);
    ASSERT_FLOAT_EQ(a.y, 3);
    ASSERT_FLOAT_EQ(a.z, 4);
    ASSERT_FLOAT_EQ(a.w, 5);

    a += b;
    
    ASSERT_FLOAT_EQ(a.x, 5);
    ASSERT_FLOAT_EQ(a.y, 4);
    ASSERT_FLOAT_EQ(a.z, 5);
    ASSERT_FLOAT_EQ(a.w, 7); 
}

TEST(Vec4Testing, CanMultiplyMemberSSEInt)
{   
    clutch::Vec4<int> a{1, 2, 3, 4};
    clutch::Vec4<int> b{3, 1, 1, 2};

    a *= 2.0;

    ASSERT_FLOAT_EQ(a.x, 2);
    ASSERT_FLOAT_EQ(a.y, 4);
    ASSERT_FLOAT_EQ(a.z, 6);
    ASSERT_FLOAT_EQ(a.w, 8);

    a *= b;
    
    ASSERT_FLOAT_EQ(a.x, 6);
    ASSERT_FLOAT_EQ(a.y, 4);
    ASSERT_FLOAT_EQ(a.z, 6);
    ASSERT_FLOAT_EQ(a.w, 16); 
}

TEST(Vec4Testing, CanSubstractMemberSSEInt)
{   
    clutch::Vec4<int> a{1, 2, 3, 4};
    clutch::Vec4<int> b{3, 1, 1, 2};

    a -= 2.0;

    ASSERT_FLOAT_EQ(a.x, -1);
    ASSERT_FLOAT_EQ(a.y, 0);
    ASSERT_FLOAT_EQ(a.z, 1);
    ASSERT_FLOAT_EQ(a.w, 2);

    a -= b;
    
    ASSERT_FLOAT_EQ(a.x, -4);
    ASSERT_FLOAT_EQ(a.y, -1);
    ASSERT_FLOAT_EQ(a.z,  0);
    ASSERT_FLOAT_EQ(a.w,  0);
}

TEST(Vec4Testing, CanDivideMemberSSEInt)
{   
    clutch::Vec4<int> a{1, 2, 3, 3};
    clutch::Vec4<int> b{3, 1, 1, 1};

    a /= 2.0;

    ASSERT_FLOAT_EQ(a.x, 0);
    ASSERT_FLOAT_EQ(a.y, 1);
    ASSERT_FLOAT_EQ(a.z, 3/2);
    ASSERT_FLOAT_EQ(a.w, 3/2);

    a /= b;
    
    ASSERT_FLOAT_EQ(a.x, 0 / 3);
    ASSERT_FLOAT_EQ(a.y, 1);
    ASSERT_FLOAT_EQ(a.z, 3/2);
    ASSERT_FLOAT_EQ(a.w, 3/2);
}

TEST(Vec4Testing, SubstractionSSEInt)
{
    clutch::Vec4<int> a{1, 2, 3, 1};
    clutch::Vec4<int> b{3, 1, 1, 1};

    auto r = a - b;

    ASSERT_FLOAT_EQ(r.x,-2);
    ASSERT_FLOAT_EQ(r.y, 1);
    ASSERT_FLOAT_EQ(r.z, 2);
    ASSERT_FLOAT_EQ(r.w, 0);
}

TEST(Vec4Testing, ScalarMultiplicationSSEInt)
{
    clutch::Vec4<int> a{1, 2, 3, 2};

    auto r = a * 4.0f;

    ASSERT_FLOAT_EQ(r.x, 4);
    ASSERT_FLOAT_EQ(r.y, 8);
    ASSERT_FLOAT_EQ(r.z, 12);
    ASSERT_FLOAT_EQ(r.w, 8);
}

TEST(Vector4Testing, VectorNegationSSEInt)
{
    clutch::Vec4<int> v{1, -2, 3, 1};
    clutch::Vec4<int> r{-1, 2,-3,-1};

    ASSERT_TRUE(-v == r);
}

TEST(Vector4Testing, VectorScalarDivitionSSEInt)
{
    clutch::Vec4<int> v{1, -2, 3, 6};
    clutch::Vec4<int> r{0, -1, 1, 3};

    ASSERT_TRUE(v / 2.0f == r);
}

TEST(Vector4Testing, VectorMagnitudeSSEInt)
{
    clutch::Vec4<int> v1{1, 0, 0, 0};
    clutch::Vec4<int> v2{0, 1, 0, 0};
    clutch::Vec4<int> v3{0, 0, 1, 0};
    clutch::Vec4<int> v4{1, 2, 3, 4};
    clutch::Vec4<int> v5{-1,-2,-3,-4};

    ASSERT_FLOAT_EQ(Mag(v1),1.0);
    ASSERT_FLOAT_EQ(Mag(v2),1.0);
    ASSERT_FLOAT_EQ(Mag(v3),1.0);
    ASSERT_FLOAT_EQ(Mag(v4),5.4772258);
    ASSERT_FLOAT_EQ(Mag(v5),5.4772258);
}

TEST(Vector4Testing, DotProductSSEInt){
    clutch::Vec4<int> v1{1, 2, 3, 1};
    clutch::Vec4<int> v2{2, 3, 4, 1};

    ASSERT_FLOAT_EQ(Dot(v1,v2),21.0);
}
/*
TEST(Vector4Testing, CrossProduct){
    clutch::Vec4<int> v1{ 1.0, 2.0, 3.0, 0.0f};
    clutch::Vec4<int> v2{ 2.0, 3.0, 4.0, 0.0f};
    clutch::Vec4<int> v3{ 1.0, 2.0,-2.0, 0.0f};
    clutch::Vec4<int> v4{ 3.0, 0.0, 1.0, 0.0f};
    clutch::Vec4<int> r1{-1.0, 2.0,-1.0, 0.0f};
    clutch::Vec4<int> r2{ 1.0,-2.0, 1.0, 0.0f};
    clutch::Vec4<int> r3{ 2.0,-7.0,-6.0, 0.0f};
    
    ASSERT_TRUE(Cross(v1,v2) == r1);
    ASSERT_TRUE(Cross(v2,v1) == r2);
    ASSERT_TRUE(Cross(v3,v4) == r3);
}
*/

TEST(Vector4Testing, Vec4NormalizeSSEInt)
{
    clutch::Vec4<int> v1{1, 2, 3, 4};

    std::cout << Mag(Normalize(v1)) << "\n";

    ASSERT_FLOAT_EQ(Mag(Normalize(v1)), 0.0);
}

// unsigned int

TEST(Vec4Testing, CanCopySSEUInt)
{
    clutch::Vec4<unsigned int> test{1, 2, 3, 4};
    auto test_copy = test;

    ASSERT_TRUE(test == test_copy); 
}

TEST(Vec4Testing, CanAccesNormalMembersSSEUInt)
{
    clutch::Vec4<unsigned int> test{1, 2, 3, 4};
    ASSERT_FLOAT_EQ(test.x, 1);
    ASSERT_FLOAT_EQ(test.y, 2);
    ASSERT_FLOAT_EQ(test.z, 3);
    ASSERT_FLOAT_EQ(test.w, 4);
    ASSERT_FLOAT_EQ(test.r, 1);
    ASSERT_FLOAT_EQ(test.g, 2);
    ASSERT_FLOAT_EQ(test.b, 3);
    ASSERT_FLOAT_EQ(test.a, 4);
}

TEST(Vec4Testing, CanAddVectorSSEUInt)
{   
    clutch::Vec4<unsigned int> a{1, 2, 3, 4};
    clutch::Vec4<unsigned int> b{3, 1, 1, 2};
    
    auto r = a + b;

    ASSERT_FLOAT_EQ(r.x, 4);
    ASSERT_FLOAT_EQ(r.y, 3);
    ASSERT_FLOAT_EQ(r.z, 4);
    ASSERT_FLOAT_EQ(r.w, 6);
}

TEST(Vec4Testing, CanAddVectorScalarSSEUInt)
{   
    clutch::Vec4<unsigned int> a{1, 2, 3, 4};
    
    auto r = a + 1;

    ASSERT_FLOAT_EQ(r.x, 2);
    ASSERT_FLOAT_EQ(r.y, 3);
    ASSERT_FLOAT_EQ(r.z, 4);
    ASSERT_FLOAT_EQ(r.w, 5);
}

TEST(Vec4Testing, CanAddMemberSSEUInt)
{   
    clutch::Vec4<unsigned int> a{1, 2, 3, 4};
    clutch::Vec4<unsigned int> b{3, 1, 1, 2};

    a += 1.0;

    ASSERT_FLOAT_EQ(a.x, 2);
    ASSERT_FLOAT_EQ(a.y, 3);
    ASSERT_FLOAT_EQ(a.z, 4);
    ASSERT_FLOAT_EQ(a.w, 5);

    a += b;
    
    ASSERT_FLOAT_EQ(a.x, 5);
    ASSERT_FLOAT_EQ(a.y, 4);
    ASSERT_FLOAT_EQ(a.z, 5);
    ASSERT_FLOAT_EQ(a.w, 7); 
}

TEST(Vec4Testing, CanMultiplyMemberSSEUInt)
{   
    clutch::Vec4<unsigned int> a{1, 2, 3, 4};
    clutch::Vec4<unsigned int> b{3, 1, 1, 2};

    a *= 2.0;

    ASSERT_FLOAT_EQ(a.x, 2);
    ASSERT_FLOAT_EQ(a.y, 4);
    ASSERT_FLOAT_EQ(a.z, 6);
    ASSERT_FLOAT_EQ(a.w, 8);

    a *= b;
    
    ASSERT_FLOAT_EQ(a.x, 6);
    ASSERT_FLOAT_EQ(a.y, 4);
    ASSERT_FLOAT_EQ(a.z, 6);
    ASSERT_FLOAT_EQ(a.w, 16); 
}

TEST(Vec4Testing, CanSubstractMemberSSEUInt)
{   
    clutch::Vec4<unsigned int> a{10, 20, 30, 40};
    clutch::Vec4<unsigned int> b{0, 1, 1, 2};

    a -= 2.0;

    ASSERT_FLOAT_EQ(a.x, 8);
    ASSERT_FLOAT_EQ(a.y, 18);
    ASSERT_FLOAT_EQ(a.z, 28);
    ASSERT_FLOAT_EQ(a.w, 38);

    a -= b;
    
    ASSERT_FLOAT_EQ(a.x, 8);
    ASSERT_FLOAT_EQ(a.y, 17);
    ASSERT_FLOAT_EQ(a.z, 27);
    ASSERT_FLOAT_EQ(a.w, 36);
}

TEST(Vec4Testing, CanDivideMember)
{   
    clutch::Vec4<unsigned int> a{1, 2, 3, 3};
    clutch::Vec4<unsigned int> b{3, 1, 1, 1};

    a /= 2.0;

    ASSERT_FLOAT_EQ(a.x, 0);
    ASSERT_FLOAT_EQ(a.y, 1);
    ASSERT_FLOAT_EQ(a.z, 3/2);
    ASSERT_FLOAT_EQ(a.w, 3/2);

    a /= b;
    
    ASSERT_FLOAT_EQ(a.x, 0 / 3);
    ASSERT_FLOAT_EQ(a.y, 1);
    ASSERT_FLOAT_EQ(a.z, 3/2);
    ASSERT_FLOAT_EQ(a.w, 3/2);
}

TEST(Vec4Testing, SubstractionSSEUInt)
{
    clutch::Vec4<unsigned int> a{11, 21, 31, 11};
    clutch::Vec4<unsigned int> b{3, 1, 1, 1};

    auto r = a - b;

    ASSERT_FLOAT_EQ(r.x, 8);
    ASSERT_FLOAT_EQ(r.y, 20);
    ASSERT_FLOAT_EQ(r.z, 30);
    ASSERT_FLOAT_EQ(r.w, 10);
}

TEST(Vec4Testing, ScalarMultiplicationSSEUInt)
{
    clutch::Vec4<unsigned int> a{1, 2, 3, 2};

    auto r = a * 4.0f;

    ASSERT_FLOAT_EQ(r.x, 4);
    ASSERT_FLOAT_EQ(r.y, 8);
    ASSERT_FLOAT_EQ(r.z, 12);
    ASSERT_FLOAT_EQ(r.w, 8);
}

TEST(Vector4Testing, VectorScalarDivitionSSEUInt)
{
    clutch::Vec4<unsigned int> v{1, 2, 3, 6};
    clutch::Vec4<unsigned int> r{0, 1, 1, 3};

    ASSERT_TRUE(v / 2.0f == r);
}

TEST(Vector4Testing, VectorMagnitudeSSEUInt)
{
    clutch::Vec4<unsigned int> v1{1, 0, 0, 0};
    clutch::Vec4<unsigned int> v2{0, 1, 0, 0};
    clutch::Vec4<unsigned int> v3{0, 0, 1, 0};
    clutch::Vec4<unsigned int> v4{1, 2, 3, 4};

    ASSERT_FLOAT_EQ(Mag(v1),1.0);
    ASSERT_FLOAT_EQ(Mag(v2),1.0);
    ASSERT_FLOAT_EQ(Mag(v3),1.0);
    ASSERT_FLOAT_EQ(Mag(v4),5.4772258);
}

TEST(Vector4Testing, DotProductSSEUInt)
{
    clutch::Vec4<unsigned int> v1{1, 2, 3, 1};
    clutch::Vec4<unsigned int> v2{2, 3, 4, 1};

    ASSERT_FLOAT_EQ(Dot(v1,v2),21.0);
}
/*
TEST(Vector4Testing, CrossProduct){
    clutch::Vec4<unsigned int> v1{ 1.0, 2.0, 3.0, 0.0f};
    clutch::Vec4<unsigned int> v2{ 2.0, 3.0, 4.0, 0.0f};
    clutch::Vec4<unsigned int> v3{ 1.0, 2.0,-2.0, 0.0f};
    clutch::Vec4<unsigned int> v4{ 3.0, 0.0, 1.0, 0.0f};
    clutch::Vec4<unsigned int> r1{-1.0, 2.0,-1.0, 0.0f};
    clutch::Vec4<unsigned int> r2{ 1.0,-2.0, 1.0, 0.0f};
    clutch::Vec4<unsigned int> r3{ 2.0,-7.0,-6.0, 0.0f};
    
    ASSERT_TRUE(Cross(v1,v2) == r1);
    ASSERT_TRUE(Cross(v2,v1) == r2);
    ASSERT_TRUE(Cross(v3,v4) == r3);
}
*/

TEST(Vector4Testing, Vec4NormalizeSSEUInt)
{
    clutch::Vec4<unsigned int> v1{1, 2, 3, 4};

    ASSERT_FLOAT_EQ(Mag(Normalize(v1)), 0.0);
}