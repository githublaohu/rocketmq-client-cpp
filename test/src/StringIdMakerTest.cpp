/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "StringIdMaker.h"
#include <map>
#include <iostream>

using namespace std;
using namespace rocketmq;
using ::testing::InitGoogleTest;
using ::testing::InitGoogleMock;
using testing::Return;

TEST(StringIdMakerTest, get_unique_id) {
  string unique_id = StringIdMaker::get_mutable_instance().get_unique_id();
  cout << "unique_id: " << unique_id << endl;
  EXPECT_EQ(unique_id.size(), 32);
}

int main(int argc, char* argv[]) {
  InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}
