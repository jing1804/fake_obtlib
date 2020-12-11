#include "gtest/gtest.h"
#include "RREService_api.h"
#include "handler.h"
class ClassTest : public testing::Test
{
public:
	virtual void SetUpTestCase()
	{

	}
	virtual void TearDownTestCase()
	{

	}
	virtual void SetUp()
	{

	}
	virtual void TearDown()
	{

	}
private:
	
};
TEST(Client, test) 
{
	ECUINFOSTR info;
	obt_log_callback_b cb;
	bool re = RREServiceInit(info, cb);
	EXPECT_EQ(re, true) << "init failure";
	EXPECT_EQ(RREServiceTcpGetTcpStatus(), 1);
	RREServiceTcpConnect();
	EXPECT_EQ(RREServiceTcpGetTcpStatus(), 3);
	EXPECT_EQ(RREServiceTcpGetDoipRaStatus(), 1);
	RREServiceTcpClose();
	EXPECT_EQ(RREServiceTcpGetTcpStatus(), 1);
}

TEST(Server, test)
{
	char strmesg[2056];
	OBT_MSG stmesg;
	stmesg.len = 10;
	short stype = CLI_SEND_MSG;
	rres_serialization(&stmesg, &stype, strmesg);
	EXPECT_EQ(stype, *((short*)strmesg));
	EXPECT_EQ(10, *((int*)&strmesg[6]));
	OBT_MSG stm;
	short st;
	rres_deserialization(strmesg, &stm, &st);
	EXPECT_EQ(stm.len, 10);
	EXPECT_EQ(st, CLI_SEND_MSG);
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
