#include <os>
#include <iostream>

using namespace std;

struct TestAddr
{
  // constructors
  TestAddr()
    : i64{0, 0} {}
  TestAddr(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
    : i32{a, b, c, d} {}
  TestAddr(uint64_t top, uint64_t bot)
    : i64{top, bot} {}
  
  // copy-constructor
  TestAddr(const TestAddr& a)
  {
    printf("TestAddr copy constructor\n");
    printf("TestAddr %s\n", a.to_string().c_str());
    
    this->i64[0] = a.i64[0];
    this->i64[1] = a.i64[1];
  }
  // move constructor
  TestAddr& operator= (const TestAddr& a)
  {
    printf("TestAddr move constructor\n");
    printf("TestAddr %s\n", a.to_string().c_str());
    
    this->i64[0] = a.i64[0];
    this->i64[1] = a.i64[1];
    return *this;
  }
  // returns this IPv6 address as a string
  std::string to_string() const;
  
  // fields
  uint64_t i64[2];
  uint32_t i32[4];
  uint16_t i16[8];
  uint8_t  i8[16];
  
};

const std::string lut = "0123456789abcdef";

std::string TestAddr::to_string() const
{
  //const std::string lut = "0123456789abcdef";
  std::string ret(40, '\0');
  int counter = 0;
  
  const uint8_t* octet = i8;
  
  for (int i = 0; i < 16; i++)
  {
    ret[counter++] = 'c'; //lut[(octet[i] & 0xF0) >> 4];
    ret[counter++] = 'd'; //lut[(octet[i] & 0x0F) >> 0];
    if (i & 1)
      ret[counter++] = ':';
  }
  printf("string: %s  len: %d\n", ret.c_str(), counter);
  ret[counter-1] = 0;
  return ret;
}


void Service::start()
{
	std::cout << "*** Service is up - with OS Included! ***" << std::endl;
	
  TestAddr ip6(1234, 1234);
  
  register void* sp asm ("sp");
  printf("stack: %p\n", sp);
  
  TestAddr test = ip6;
  std::cout << "ip6 = " << ip6.to_string() << std::endl;
  printf("ipv6 %s\n", ip6.to_string().c_str());
}
