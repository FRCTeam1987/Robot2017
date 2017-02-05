//
//  FileParserTest.cpp
//  Drive-Path
//
//  Created by Ken Schenke on 1/23/17.
//  Copyright © 2017 Ken Schenke. All rights reserved.
//

#ifdef FOR_TEST

#include "../../../src/Lib/TrajectoryStuff/FileParser.h"
#include <gtest/gtest.h>

#include <sstream>

class FileParserTest : public FileParser, public testing::Test
{
    
};

TEST_F(FileParserTest, splitStringTest)
{
    vector<string> fields = splitString("a b c d", ' ');
    EXPECT_EQ(4, fields.size());
    EXPECT_EQ("a", fields[0]);
    EXPECT_EQ("b", fields[1]);
    EXPECT_EQ("c", fields[2]);
    EXPECT_EQ("d", fields[3]);
}

TEST_F(FileParserTest, ignoreHeaderLinesTest)
{
    std::stringstream stream;
    
    stream << "ignore line 1" << std::endl;
    stream << "1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0" << std::endl;  // this line should also be ignored
    stream << "2.0 3.0 4.0 5.0 6.0 7.0 8.0 9.0" << std::endl;
    stream << "3.0 4.0 5.0 6.0 7.0 8.0 9.0 10.0" << std::endl;
    
    vector<Trajectory> trajectories = parseStream(stream);
    EXPECT_EQ(2, trajectories.size());

    double base = 2.0;
    for(vector<Trajectory>::iterator it=trajectories.begin(); it!=trajectories.end(); ++it,base++)
    {
        ASSERT_EQ(base+0.0, it->getPosition());
        ASSERT_EQ(base+1.0, it->getVelocity());
        ASSERT_EQ(base+2.0, it->getAcceleration());
        ASSERT_EQ(base+3.0, it->getJerk());
        ASSERT_EQ(base+4.0, it->getHeading());
        ASSERT_EQ(base+5.0, it->getDeltaTime());
        ASSERT_EQ(base+6.0, it->getX());
        ASSERT_EQ(base+7.0, it->getY());
    }
}

TEST_F(FileParserTest, ignoreLinesWithoutEightFields)
{
    std::stringstream stream;
    
    stream << "ignore line 1" << std::endl;
    stream << "ignore line 2" << std::endl;
    stream << "2.0 3.0 4.0 5.0 6.0 7.0 8.0 9.0" << std::endl;
    stream << "2.0 3.0 4.0 5.0 6.0 7.0 8.0 9.0 10.0" << std::endl;  // this line should be ignored
    stream << "3.0 4.0 5.0 6.0 7.0 8.0 9.0 10.0" << std::endl;
    
    vector<Trajectory> trajectories = parseStream(stream);
    EXPECT_EQ(2, trajectories.size());
    
    double base = 2.0;
    for(vector<Trajectory>::iterator it=trajectories.begin(); it!=trajectories.end(); ++it,base++)
    {
        ASSERT_EQ(base+0.0, it->getPosition());
        ASSERT_EQ(base+1.0, it->getVelocity());
        ASSERT_EQ(base+2.0, it->getAcceleration());
        ASSERT_EQ(base+3.0, it->getJerk());
        ASSERT_EQ(base+4.0, it->getHeading());
        ASSERT_EQ(base+5.0, it->getDeltaTime());
        ASSERT_EQ(base+6.0, it->getX());
        ASSERT_EQ(base+7.0, it->getY());
    }
}

#endif //End of FOR_TEST
