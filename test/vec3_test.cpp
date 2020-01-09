#include <gtest/gtest.h>
#include <math.h>
#include <iostream>
#include "../include/vec3.hpp"

TEST(Vec3Testing, CanCopy)
{
    clutch::Vec3<float> test{1.0f, 2.0f, 3.0f};
    auto test_copy = test;

    ASSERT_TRUE(test == test_copy); 
}

TEST(Vec3Testing, CanAccesNormalMembers)
{
    clutch::Vec3<float> test{1.0f, 2.0f, 3.0f};
    ASSERT_FLOAT_EQ(test.x, 1.0f);
    ASSERT_FLOAT_EQ(test.y, 2.0f);
    ASSERT_FLOAT_EQ(test.z, 3.0f);
    ASSERT_FLOAT_EQ(test.r, 1.0f);
    ASSERT_FLOAT_EQ(test.g, 2.0f);
    ASSERT_FLOAT_EQ(test.b, 3.0f);
}

TEST(Vec3Testing, CanAddVector)
{   
    clutch::Vec3<float> a{1.0f, 2.0f, 3.0f};
    clutch::Vec3<float> b{3.0f, 1.0f, 1.0f};
    
    auto r = a + b;

    ASSERT_FLOAT_EQ(r.x, 4.0f);
    ASSERT_FLOAT_EQ(r.y, 3.0f);
    ASSERT_FLOAT_EQ(r.z, 4.0f);
}

TEST(Vec3Testing, CanAddVectorScalar)
{   
    clutch::Vec3<float> a{1.0f, 2.0f, 3.0f};
    
    auto r = a + 1;

    ASSERT_FLOAT_EQ(r.x, 2.0f);
    ASSERT_FLOAT_EQ(r.y, 3.0f);
    ASSERT_FLOAT_EQ(r.z, 4.0f);
}

TEST(Vec3Testing, CanAddMember)
{   
    clutch::Vec3<float> a{1.0f, 2.0f, 3.0f};
    clutch::Vec3<float> b{3.0f, 1.0f, 1.0f};

    a += 1.0;

    ASSERT_FLOAT_EQ(a.x, 2.0f);
    ASSERT_FLOAT_EQ(a.y, 3.0f);
    ASSERT_FLOAT_EQ(a.z, 4.0f);

    a += b;
    
    ASSERT_FLOAT_EQ(a.x, 5.0f);
    ASSERT_FLOAT_EQ(a.y, 4.0f);
    ASSERT_FLOAT_EQ(a.z, 5.0f); 
}

TEST(Vec3Testing, CanMultiplyMember)
{   
    clutch::Vec3<float> a{1.0f, 2.0f, 3.0f};
    clutch::Vec3<float> b{3.0f, 1.0f, 1.0f};

    a *= 2.0;

    ASSERT_FLOAT_EQ(a.x, 2.0f);
    ASSERT_FLOAT_EQ(a.y, 4.0f);
    ASSERT_FLOAT_EQ(a.z, 6.0f);

    a *= b;
    
    ASSERT_FLOAT_EQ(a.x, 6.0f);
    ASSERT_FLOAT_EQ(a.y, 4.0f);
    ASSERT_FLOAT_EQ(a.z, 6.0f); 
}

TEST(Vec3Testing, CanSubstractMember)
{   
    clutch::Vec3<float> a{1.0f, 2.0f, 3.0f};
    clutch::Vec3<float> b{3.0f, 1.0f, 1.0f};

    a -= 2.0;

    ASSERT_FLOAT_EQ(a.x, -1.0f);
    ASSERT_FLOAT_EQ(a.y, 0.0f);
    ASSERT_FLOAT_EQ(a.z, 1.0f);

    a -= b;
    
    ASSERT_FLOAT_EQ(a.x, -4.0f);
    ASSERT_FLOAT_EQ(a.y, -1.0f);
    ASSERT_FLOAT_EQ(a.z,  0.0f);
}

TEST(Vec3Testing, CanDivideMember)
{   
    clutch::Vec3<float> a{1.0f, 2.0f, 3.0f};
    clutch::Vec3<float> b{3.0f, 1.0f, 1.0f};

    a /= 2.0;

    ASSERT_FLOAT_EQ(a.x, 0.5f);
    ASSERT_FLOAT_EQ(a.y, 1.0f);
    ASSERT_FLOAT_EQ(a.z, 3.0f/2.0f);

    a /= b;
    
    ASSERT_FLOAT_EQ(a.x, 0.5f / 3.0f);
    ASSERT_FLOAT_EQ(a.y, 1.0f);
    ASSERT_FLOAT_EQ(a.z, 3.0f/2.0f);
}

TEST(Vec3Testing, Substraction)
{
    clutch::Vec3<float> a{1.0f, 2.0f, 3.0f};
    clutch::Vec3<float> b{3.0f, 1.0f, 1.0f};

    auto r = a - b;

    ASSERT_FLOAT_EQ(r.x,-2.0f);
    ASSERT_FLOAT_EQ(r.y, 1.0f);
    ASSERT_FLOAT_EQ(r.z, 2.0f);
}

TEST(Vec3Testing, ScalarMultiplication)
{
    clutch::Vec3<float> a{1.0f, 2.0f, 3.0f};

    auto r = a * 4.0f;

    ASSERT_FLOAT_EQ(r.x, 4.0f);
    ASSERT_FLOAT_EQ(r.y, 8.0f);
    ASSERT_FLOAT_EQ(r.z, 12.0f);
}


TEST(VectorTesting, VectorNegation){
    clutch::Vec3<float> v{1.0f, -2.0f, 3.0f};
    clutch::Vec3<float> r{-1.0f, 2.0f,-3.0f};

    ASSERT_TRUE(-v == r);
}

TEST(VectorTesting, VectorScalarDivition){
    clutch::Vec3<float> v{1.0f, -2.0f, 3.0f};
    clutch::Vec3<float> r{0.5f, -1.0f, 1.5f};

    ASSERT_TRUE(v / 2.0f == r);
}

TEST(VectorTesting, VectorMagnitude){
    clutch::Vec3<float> v1{1.0f, 0.0f, 0.0f};
    clutch::Vec3<float> v2{0.0f, 1.0f, 0.0f};
    clutch::Vec3<float> v3{0.0f, 0.0f, 1.0f};
    clutch::Vec3<float> v4{1.0f, 2.0f, 3.0f};
    clutch::Vec3<float> v5{-1.0f,-2.0,-3.0f};

    ASSERT_FLOAT_EQ(Mag(v1),1.0);
    ASSERT_FLOAT_EQ(Mag(v2),1.0);
    ASSERT_FLOAT_EQ(Mag(v3),1.0);
    ASSERT_FLOAT_EQ(Mag(v4),sqrt(14));
    ASSERT_FLOAT_EQ(Mag(v5),sqrt(14));
}

TEST(VectorTesting, DotProduct){
    clutch::Vec3<float> v1{1.0f, 2.0f, 3.0f};
    clutch::Vec3<float> v2{2.0f, 3.0f, 4.0f};

    ASSERT_FLOAT_EQ(Dot(v1,v2),20.0);
}

TEST(VectorTesting, CrossProduct){
    clutch::Vec3<float> v1{1.0, 2.0, 3.0};
    clutch::Vec3<float> v2{2.0, 3.0, 4.0};
    clutch::Vec3<float> v3{1.0, 2.0, -2.0};
    clutch::Vec3<float> v4{3.0, 0.0, 1.0};
    clutch::Vec3<float> r1{-1.0, 2.0, -1.0};
    clutch::Vec3<float> r2{1.0, -2.0, 1.0};
    clutch::Vec3<float> r3{2.0, -7.0, -6.0};
    
    ASSERT_TRUE(Cross(v1,v2) == r1);
    ASSERT_TRUE(Cross(v2,v1) == r2);
    ASSERT_TRUE(Cross(v3,v4) == r3);
}