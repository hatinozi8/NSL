
declare PS_PAD_M{

	output	PAD_CLK;
	output	PAD_SEL;
	output	PAD_CMD;
	input	PAD_DAT;
	input	PAD_ACK;

	func_in  com_start;
	func_out com_end();

	output	id[4];
	output	data[16];
	
	output	debug_state[6];
}


