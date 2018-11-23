/*
        ip: 4
        pid: 4
        随机数 :2
        时间：4
        自增数:2
*/
#ifndef __STRINGID_MAKER_H__
#define __STRINGID_MAKER_H__

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <boost/serialization/singleton.hpp>
#include <string>
#include <boost/asio.hpp>

#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <sys/time.h>
#endif

#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <sys/time.h>
#endif

namespace rocketmq {
class StringIdMaker : public boost::serialization::singleton<StringIdMaker> {
 public:
  StringIdMaker();
  ~StringIdMaker();
  std::string get_unique_id();

 private:
  uint32_t get_ip();
  void init_prefix();
  uint64_t get_curr_ms();
  int atomic_incr(int id);
  void set_start_and_next_tm();

  void hexdump(unsigned char *buffer, char *out_buff, unsigned long index);

 private:
  uint64_t _start_tm;
  uint64_t _next_start_tm;
  unsigned char _buff[16];
  char _0x_buff[33];
  int16_t seqid;
};
}
#endif
