
#define N 16
//#define RC 5
//#define RC 6
#define RC 8	//R=150 , C=47n fc=22.5khz

declare DAC{
	input	datai[N];
	output	vo;

	func_in set_data( datai );
}

