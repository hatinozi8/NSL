

#define N 16
#define BUF_SIZE 257
//#define BUF_CENTER ((BUF_SIZE-1)>>1)
#define BUF_CENTER 128


struct BUF{
	L[N];
	R[N];
};


declare OVS{

	input Rin[N];
	input Lin[N];
	output Rout[N];
	output Lout[N];

	func_in push(Rin,Lin);
	func_out pop(Rout,Lout);
}


