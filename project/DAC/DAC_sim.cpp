#include <systemc.h>
#include <systemc-ams.h>

#include "DAC.sh"
#include "LPF.h"
#include "FPGA.h"

int sc_main(int argn,char* argc[]){

	DAC dac_i("dac_i");

	//LPF lpf_i("lpf_i",150,8.2e-9);
	//LPF lpf_i("lpf_i",200,3.3e-9);
	LPF lpf_i("lpf_i",600,2.2e-9);
	LPF lpf2_i("lpf2_i",150,22e-9);


	FPGA_OUT fpga_gpio0("fpga_gpio0");

	
	sc_clock m_clock("m_clock",20833,SC_PS);
	sc_signal<bool> p_reset;
	sc_signal<sc_uint<16> > datai;
	sc_signal<sc_uint<1> > set_data;

	sc_signal<sc_uint<1> > dac_out;

	sca_tdf::sca_signal<double> dac_out_fpga;
	sca_tdf::sca_signal<double> dac_out_lpf;

	sca_tdf::sca_signal<double> dac_out_lpf2;

	dac_i.p_reset(p_reset);
	dac_i.m_clock(m_clock);
	dac_i.datai(datai);
	dac_i.vo(dac_out);
	dac_i.set_data(set_data);


//DAC-----------------------------------------------------------
	fpga_gpio0.in(dac_out);
	fpga_gpio0.out(dac_out_fpga);

	lpf_i.in(dac_out_fpga);
	lpf_i.out(dac_out_lpf);

	lpf2_i.in(dac_out_lpf);
	lpf2_i.out(dac_out_lpf2);

//--------------------------------------------------------------




	sca_trace_file* tfp = sca_create_vcd_trace_file("DAC");
	//sca_trace_file* tfp = sca_create_tabular_trace_file("TOP");

	sca_trace(tfp,datai,"datai");
	sca_trace(tfp,m_clock,"m_clock");
	sca_trace(tfp,dac_i.vc,"vc");
	sca_trace(tfp,dac_i.vref,"vref");
	sca_trace(tfp,dac_out,"dac_out");
	sca_trace(tfp,dac_out_fpga,"dac_out_fpga");
	sca_trace(tfp,lpf_i.out,"dac_out_lpf");
	sca_trace(tfp,lpf2_i.out,"dac_out_lpf2");


	//run


	p_reset=0;
	datai=0x3FFF;
	sc_start(30.0,SC_NS);
	p_reset=1;
	sc_start(10,SC_US);
	for(int i = 0 ; i < 0xFF00 ; i +=0x100 ){
		datai = i & 0xFFFF;
		sc_start(10,SC_US);
	}
		
	sc_start(10,SC_US);
	datai=0x7FFF;
	sc_start(10,SC_US);
	datai=0x1FFF;
	sc_start(10,SC_US);
	datai=0xFFFF;

	sc_start(23,SC_US);
	datai=0xCFFF;
	sc_start(23,SC_US);
	datai=0;
	sc_start(23,SC_US);
	datai=0xFFFF;
	sc_start(23,SC_US);
	datai=0;
	sc_start(23,SC_US);
	datai=0xFFFF;
	sc_start(23,SC_US);
	datai=0;
	
	//sc_start(1.0,SC_MS);


	sca_close_vcd_trace_file(tfp);
	//sca_close_tabular_trace_file(tfp);

	return 0;

}

