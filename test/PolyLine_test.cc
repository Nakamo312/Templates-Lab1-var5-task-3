#include <gtest/gtest.h>
#include <complex>
#include <PolyLine.h>
#include <typeinfo>
using namespace Line;
using namespace std;



TEST(PolyLineTests, ConstructTypePoint)
{
    PolyLine<int> intPolyline(2, 3);
    PolyLine<float> floatPolyline(2.1f, 3.3f);
    PolyLine<double> doublePolyline(5.1f, 3.8f);
    PolyLine<complex<float>> complexFloatPolyline(5.1f, 3.8f);

    EXPECT_EQ(intPolyline.size(), 1);
    EXPECT_EQ(floatPolyline.size(), 1);
    EXPECT_EQ(doublePolyline.size(), 1);
    EXPECT_EQ(complexFloatPolyline.size(), 1);

    EXPECT_EQ(intPolyline[0].x, 2);
    EXPECT_EQ(intPolyline[0].y, 3);

    EXPECT_EQ(floatPolyline[0].x, 2.1f);
    EXPECT_EQ(floatPolyline[0].y, 3.3f);

    EXPECT_EQ(doublePolyline[0].x, 5.1f);
    EXPECT_EQ(doublePolyline[0].y, 3.8f);

    EXPECT_EQ(complexFloatPolyline[0].x, 5.1f);
    EXPECT_EQ(complexFloatPolyline[0].y, 3.8f);

}
TEST(PolyLineTests, ConstructCopy)
{
    PolyLine<int> intPolyline(2, 3);
    PolyLine<float> floatPolyline(2.1f, 3.3f);
    PolyLine<double> doublePolyline(5.1f, 3.8f);
    PolyLine<complex<float>> complexFloatPolyline(5.1f, 3.8f);

    PolyLine<int> intPolyline2(intPolyline);
    PolyLine<float> floatPolyline2(floatPolyline);
    PolyLine<double> doublePolyline2(doublePolyline);
    PolyLine<complex<float>> complexFloatPolyline2(complexFloatPolyline);
    
    EXPECT_EQ(intPolyline2.size(), 1);
    EXPECT_EQ(floatPolyline2.size(), 1);
    EXPECT_EQ(doublePolyline2.size(), 1);
    EXPECT_EQ(complexFloatPolyline2.size(), 1);

    EXPECT_EQ(intPolyline2[0].x, 2);
    EXPECT_EQ(intPolyline2[0].y, 3);

    EXPECT_EQ(floatPolyline2[0].x, 2.1f);
    EXPECT_EQ(floatPolyline2[0].y, 3.3f);

    EXPECT_EQ(doublePolyline2[0].x, 5.1f);
    EXPECT_EQ(doublePolyline2[0].y, 3.8f);

    EXPECT_EQ(complexFloatPolyline2[0].x, 5.1f);
    EXPECT_EQ(complexFloatPolyline2[0].y, 3.8f);

}
TEST(PolyLineTests, ConstructRandom)
{
    PolyLine<int> intPolyline(1, 5, 10);
    PolyLine<float> floatPolyline(2.1f, 3.3f,10);

    size_t countInt = 0;
    size_t countFloat = 0;


    for (int i = 0; i < intPolyline.size(); ++i)
    {        
        if ((intPolyline[i].x <= 5) and (intPolyline[i].x >= 1) and (intPolyline[i].y <= 5) and (intPolyline[i].y >= 1))
        {
            countInt += 1;
        }
        if ((floatPolyline[i].x <= 3.3f) and (floatPolyline[i].x >= 2.1f) and (floatPolyline[i].y <= 3.3f) and (floatPolyline[i].y >= 2.1f))
        {
            countFloat += 1;
        }
    }
   
    EXPECT_EQ(intPolyline.size(), 10);
    EXPECT_EQ(floatPolyline.size(), 10);   
    EXPECT_EQ(countInt, 10);
    EXPECT_EQ(countFloat, 10);

}
TEST(PolyLineTests, Access_by_index)
{
    PolyLine<int> intPolyline(2,3);
    PolyLine<float> floatPolyline(2.1f, 3.3f);

    EXPECT_EQ(intPolyline[0].x, 2);
    EXPECT_EQ(intPolyline[0].y, 3);
    
    EXPECT_EQ(floatPolyline[0].x, 2.1f);
    EXPECT_EQ(floatPolyline[0].y, 3.3f);

    intPolyline[0] = Point<int>(1, 1);
    floatPolyline[0] = Point<float>(1.1f, 1.1f);

    EXPECT_EQ(intPolyline[0].x, 1);
    EXPECT_EQ(intPolyline[0].y, 1);

    EXPECT_EQ(floatPolyline[0].x, 1.1f);
    EXPECT_EQ(floatPolyline[0].y, 1.1f);
}

TEST(PolyLineTests, PolylinyConPolyline)
{    
    PolyLine<float> floatPolyline(4);
    floatPolyline[0] = Point(1.1f, 1.1f);
    floatPolyline[1] = Point(2.2f, 2.2f);
    floatPolyline[2] = Point(3.3f, 3.3f);
    floatPolyline[3] = Point(4.4f, 4.4f);

    PolyLine<float> floatPolyline2(3);
    floatPolyline2[0] = Point(5.5f, 5.5f);
    floatPolyline2[1] = Point(6.6f, 6.6f);
    floatPolyline2[2] = Point(7.7f, 7.7f);

    PolyLine<float> floatPolyline3 = floatPolyline + floatPolyline2;
    EXPECT_EQ(floatPolyline3.size(), 7);
    EXPECT_EQ(floatPolyline3[0].x, 1.1f);
    EXPECT_EQ(floatPolyline3[0].y, 1.1f);
    EXPECT_EQ(floatPolyline3[1].x, 2.2f);
    EXPECT_EQ(floatPolyline3[1].y, 2.2f);
    EXPECT_EQ(floatPolyline3[2].x, 3.3f);
    EXPECT_EQ(floatPolyline3[2].y, 3.3f);
    EXPECT_EQ(floatPolyline3[3].x, 4.4f);
    EXPECT_EQ(floatPolyline3[3].y, 4.4f);
    EXPECT_EQ(floatPolyline3[4].x, 5.5f);
    EXPECT_EQ(floatPolyline3[4].y, 5.5f);
    EXPECT_EQ(floatPolyline3[5].x, 6.6f);
    EXPECT_EQ(floatPolyline3[5].y, 6.6f);
    EXPECT_EQ(floatPolyline3[6].x, 7.7f);
    EXPECT_EQ(floatPolyline3[6].y, 7.7f);

}
TEST(PolyLineTests, PolylineConPoint)
{
    PolyLine<float> floatPolyline(4);
    floatPolyline[0] = Point(1.1f, 1.1f);
    floatPolyline[1] = Point(2.2f, 2.2f);
    floatPolyline[2] = Point(3.3f, 3.3f);
    floatPolyline[3] = Point(4.4f, 4.4f);

    Point<float> p(5.5f, 5.5f);

    PolyLine<float> floatPolyline3 = floatPolyline + p;
    EXPECT_EQ(floatPolyline3.size(), 5);
    EXPECT_EQ(floatPolyline3[0].x, 1.1f);
    EXPECT_EQ(floatPolyline3[0].y, 1.1f);
    EXPECT_EQ(floatPolyline3[1].x, 2.2f);
    EXPECT_EQ(floatPolyline3[1].y, 2.2f);
    EXPECT_EQ(floatPolyline3[2].x, 3.3f);
    EXPECT_EQ(floatPolyline3[2].y, 3.3f);
    EXPECT_EQ(floatPolyline3[3].x, 4.4f);
    EXPECT_EQ(floatPolyline3[3].y, 4.4f);
    EXPECT_EQ(floatPolyline3[4].x, 5.5f);
    EXPECT_EQ(floatPolyline3[4].y, 5.5f);

}
TEST(PolyLineTests, PointConPolyline)
{
    PolyLine<float> floatPolyline(4);
    floatPolyline[0] = Point(2.2f, 2.2f);
    floatPolyline[1] = Point(3.3f, 3.3f);
    floatPolyline[2] = Point(4.4f, 4.4f);
    floatPolyline[3] = Point(5.5f, 5.5f);

    Point<float> p(1.1f, 1.1f);

    PolyLine<float> floatPolyline3 = p + floatPolyline ;
    EXPECT_EQ(floatPolyline3.size(), 5);
    EXPECT_EQ(floatPolyline3[0].x, 1.1f);
    EXPECT_EQ(floatPolyline3[0].y, 1.1f);
    EXPECT_EQ(floatPolyline3[1].x, 2.2f);
    EXPECT_EQ(floatPolyline3[1].y, 2.2f);
    EXPECT_EQ(floatPolyline3[2].x, 3.3f);
    EXPECT_EQ(floatPolyline3[2].y, 3.3f);
    EXPECT_EQ(floatPolyline3[3].x, 4.4f);
    EXPECT_EQ(floatPolyline3[3].y, 4.4f);
    EXPECT_EQ(floatPolyline3[4].x, 5.5f);
    EXPECT_EQ(floatPolyline3[4].y, 5.5f);
}
TEST(PolyLineTests, Assignment_operator_polyline)
{
    PolyLine<float> floatPolyline(1);
    floatPolyline[0] = Point(2.2f, 2.2f);
    
    PolyLine<float> floatPolyline2 = floatPolyline;
    EXPECT_EQ(floatPolyline2.size(), 1);
    EXPECT_EQ(floatPolyline2[0].x, 2.2f);
    EXPECT_EQ(floatPolyline2[0].y, 2.2f);
    

}
TEST(PolyLineTests, Addition_operator_by_assignment)
{
    PolyLine<float> floatPolyline1(1);
    floatPolyline1[0] = Point(2.2f, 2.2f);

    PolyLine<float> floatPolyline2(1);
    floatPolyline2[0] = Point(3.2f, 3.2f);

    floatPolyline1 += floatPolyline2;
    EXPECT_EQ(floatPolyline1.size(), 2);
    EXPECT_EQ(floatPolyline1[0].x, 2.2f);
    EXPECT_EQ(floatPolyline1[0].y, 2.2f);
    EXPECT_EQ(floatPolyline1[1].x, 3.2f);
    EXPECT_EQ(floatPolyline1[1].y, 3.2f);

    floatPolyline1 += Point(4.2f, 4.2f);
    EXPECT_EQ(floatPolyline1.size(), 3);
    EXPECT_EQ(floatPolyline1[0].x, 2.2f);
    EXPECT_EQ(floatPolyline1[0].y, 2.2f);
    EXPECT_EQ(floatPolyline1[1].x, 3.2f);
    EXPECT_EQ(floatPolyline1[1].y, 3.2f);
    EXPECT_EQ(floatPolyline1[2].x, 4.2f);
    EXPECT_EQ(floatPolyline1[2].y, 4.2f);
}
TEST(PolyLineTests, Length_of_polyline)
{
    PolyLine<float> floatPolyline1(1);
    floatPolyline1[0] = Point(0.f, 0.f);

    PolyLine<float> floatPolyline2(1);
    floatPolyline2[0] = Point(3.0f, 4.0f);

    floatPolyline1 += floatPolyline2;
    floatPolyline1 += Point(6.0f, 0.0f);

    EXPECT_EQ(floatPolyline1.length(0,2), 10.f);
}



