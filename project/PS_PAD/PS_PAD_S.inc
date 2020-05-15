
declare PS_PAD_S{
	//  16'{ [],x,o,^,R1,L1,R2,L2,L,D,R,U,St,_,_,Sel }
	input	KEY[16];

	input	PAD_SEL;
	input	PAD_CMD;
	input	PAD_CLK;
	output	PAD_DAT;
	output	PAD_ACK;

	output	debug[16];
	
}
