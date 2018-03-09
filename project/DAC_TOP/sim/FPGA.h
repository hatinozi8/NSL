#include <systemc-ams.h>

#define VDD 3.3

SCA_TDF_MODULE(FPGA_OUT){

	//sc_core::sc_in<sc_uint<1> > in;
	sca_tdf::sca_de::sca_in<sc_uint<1> > in;
	//sca_tdf::sca_de::sca_in<bool > in;
	//sc_core::sc_out<double> out;
	sca_tdf::sca_out<double> out;
	//sc_core::sc_in<bool> clk;

	sca_core::sca_time max_timestep;

	void set_attributes(){
		this->set_timestep(1.0,SC_NS);
		//this->set_timestep(max_timestep);
		//this->does_attribute_changes();
	}

	void processing(){
		if(in.read())	out=VDD;
		else			out=0;
	}

	//void change_attributes(){
		//this->request_next_activation(max_timestep,in->default_event());
	//}

	SCA_CTOR(FPGA_OUT){}
};

/*
SCA_TDF_MODULE(FPGA_IN){

	sca_tdf::sca_in<double> in;
	sca_tdf::sca_de::sca_out<sc_uint<1> > out;
	//sc_core::sc_in<bool> clk;

	sca_core::sca_time max_timestep;

	void set_attributes(){
		this->set_timestep(1.0,SC_NS);
	}

	void processing(){
		if(in.read()>(VDD/2))	out=1;
		else					out=0;
	}

	SCA_CTOR(FPGA_IN){}
};
*/

SC_MODULE(FPGA_IN){
	sc_core::sc_in<double> in;
	sc_core::sc_out<sc_uint<1> > out;
	sc_core::sc_in<bool> clk;

	void conv(void);

	SC_CTOR(FPGA_IN)
	:in("in"), out("out")
	{
		SC_METHOD(conv);
		sensitive <<clk;
	};
};

void FPGA_IN::conv(){
	if(FPGA_IN::in.read()>(VDD/2)) 	FPGA_IN::out.write(1);
	else							FPGA_IN::out.write(0);
}


