#define DATA_BIT 16
declare i2s{
	input	LRCLK;
	input	DATA;
	output	Ldata[DATA_BIT];
	output	Rdata[DATA_BIT];

	output	Lout;
	output	Rout;
}
