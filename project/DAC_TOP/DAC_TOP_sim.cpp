#include <systemc.h>
#include <systemc-ams.h>

#include "DAC_TOP.sh"
#include "LPF.h"
#include "FPGA.h"
#include "sin_source.h"

const int bclk_period = 354308;
const int fpga_period = 20833;

sc_signal<sc_uint<1> > data;
sc_signal<sc_uint<1> > lrclk;

void send_i2s(int L, int R){
	lrclk = 0;
	//sc_start(bclk_period,SC_PS);
	for(int i = 15 ; i>=0 ; i--){
		data = (L>>i)&0x1;
		if(i==0) lrclk = 1;
		sc_start(bclk_period,SC_PS);
	}
	lrclk = 1;
	for(int i = 15 ; i>=0 ; i--){
		data = (R>>i)&0x1;
		if(i==0) lrclk = 0;
		sc_start(bclk_period,SC_PS);
	}
}

int sc_main(int argn,char* argc[]){

	DAC_TOP dac_i("dac_i");

	//LPF lpf_i("lpf_i",150,8.2e-9);
	//LPF lpf_i("lpf_i",200,3.3e-9);
	//LPF lpf_R("lpf_R",600,2.2e-9);
	//LPF lpf_L("lpf_L",600,2.2e-9);
	LPF lpf_R("lpf_R",150,47e-9); //fc 22.5khz
	LPF lpf_L("lpf_L",150,47e-9); //fc 22.5khz
	LPF lpf2_R("lpf2_R",300,47e-9);
	LPF lpf2_L("lpf2_L",200,47e-9);

	sin_source sin_1("sin_1");

	FPGA_OUT fpga_gpioR("fpga_gpioR");
	FPGA_OUT fpga_gpioL("fpga_gpioL");

	
	sc_clock m_clock("m_clock",fpga_period,SC_PS);
	sc_clock bclk("bclk",bclk_period,SC_PS);
	sc_signal<bool> p_reset;
	//sc_signal<sc_uint<1> > bclk_t;
	
	//sc_signal<sc_uint<16> > datai;
	//sc_signal<sc_uint<1> > set_data;

	sc_signal<sc_uint<1> > dac_out_R;
	sc_signal<sc_uint<1> > dac_out_L;
	//sc_signal<bool > dac_out_R;
	//sc_signal<bool > dac_out_L;

	sca_tdf::sca_signal<double> dac_out_fpga_R;
	sca_tdf::sca_signal<double> dac_out_fpga_L;
	sca_tdf::sca_signal<double> dac_out_lpf_R;
	sca_tdf::sca_signal<double> dac_out_lpf_L;
	sca_tdf::sca_signal<double> sin_sig1;

	sca_tdf::sca_signal<double> dac_out_lpf2_R;
	sca_tdf::sca_signal<double> dac_out_lpf2_L;

	//bclk_t =

	dac_i.p_reset(p_reset);
	dac_i.m_clock(m_clock);
	dac_i.BCLK(bclk);
	dac_i.DATA(data);
	dac_i.LRCLK(lrclk);
	dac_i.V_OUT_R(dac_out_R);
	dac_i.V_OUT_L(dac_out_L);


//DAC-----------------------------------------------------------
	fpga_gpioR.in(dac_out_R);
	fpga_gpioR.out(dac_out_fpga_R);

	lpf_R.in(dac_out_fpga_R);
	lpf_R.out(dac_out_lpf_R);

	fpga_gpioL.in(dac_out_L);
	fpga_gpioL.out(dac_out_fpga_L);

	lpf_L.in(dac_out_fpga_L);
	lpf_L.out(dac_out_lpf_L);

	sin_1.out(sin_sig1);

	lpf2_R.in(dac_out_lpf_R);
	lpf2_R.out(dac_out_lpf2_R);

	lpf2_L.in(dac_out_lpf_L);
	lpf2_L.out(dac_out_lpf2_L);

//--------------------------------------------------------------




	sca_trace_file* tfp = sca_create_vcd_trace_file("DAC");
	//sca_trace_file* tfp = sca_create_tabular_trace_file("TOP");

	//sca_trace(tfp,datai,"datai");
	sca_trace(tfp,m_clock,"m_clock");
	sca_trace(tfp,bclk,"bclk");
	sca_trace(tfp,data,"data");
	sca_trace(tfp,lrclk,"lrclk");
	sca_trace(tfp,dac_i.dac_R.vi,"R_vi");
	sca_trace(tfp,dac_i.dac_L.vi,"L_vi");
	sca_trace(tfp,dac_i.dac_R.set_data,"R_set");
	sca_trace(tfp,dac_i.i2s_i.dataL,"dataL");
	sca_trace(tfp,dac_i.i2s_i.dataR,"dataR");

	sca_trace(tfp,dac_i.sync_B2,"sync_B2");
	sca_trace(tfp,dac_i.ovs_i.Rin,"ovs_i.Rin");
	sca_trace(tfp,dac_i.ovs_i.Rout,"ovs_i.Rout");
	sca_trace(tfp,dac_i.ovs_i.push,"ovs_i.push");
	sca_trace(tfp,dac_i.ovs_i.pop,"ovs_i.pop");

	//sca_trace(tfp,dac_i.vc,"vc");
	//sca_trace(tfp,dac_i.vref,"vref");
	sca_trace(tfp,dac_out_R,"dac_out_R");
	sca_trace(tfp,dac_out_L,"dac_out_L");
	sca_trace(tfp,dac_out_fpga_R,"dac_out_fpga_R");
	sca_trace(tfp,dac_out_fpga_L,"dac_out_fpga_L");
	sca_trace(tfp,lpf_R.out,"dac_out_lpf_R");
	sca_trace(tfp,lpf_L.out,"dac_out_lpf_L");
	sca_trace(tfp,sin_sig1,"sin_sig1");

	sca_trace(tfp,dac_out_lpf2_L,"dac_out_lpf2_L");
	sca_trace(tfp,dac_out_lpf2_R,"dac_out_lpf2_R");
	//sca_trace(tfp,lpf2_i.out,"dac_out_lpf2");


	//run

	double sin_tmp;
	int sin_16;

	p_reset=0;
	sc_start(bclk_period*10,SC_PS);
	p_reset=1;
	lrclk = 1;
	sc_start(bclk_period*4,SC_PS);
	
	sc_start(bclk_period/2,SC_PS);
	
	lrclk = 0;
	sc_start(bclk_period,SC_PS);

	send_i2s(0xAAAA,0x5555);
	send_i2s(0x0000,0x0000);

	send_i2s(0x8000,0xFFFF);
	send_i2s(0xFFFF,0x8000);
	send_i2s(0xFFFF,0xFFFF);
	send_i2s(0xFFFF,0xFFFF);

	for(int i = 0 ; i<100 ; i++){
		sin_tmp = sin_sig1.read(0)+0.5;
		sin_16 = ((int)(sin_tmp*0xFFFF))&0xFFFF;
		send_i2s(sin_16,sin_16);
	}

	sin_1.freq = 2e3;

	for(int i = 0 ; i<100 ; i++){
		sin_tmp = sin_sig1.read(0)+0.5;
		sin_16 = ((int)(sin_tmp*0xFFFF))&0xFFFF;
		send_i2s(sin_16,sin_16);
	}
	
	sin_1.freq = 10e3;

	for(int i = 0 ; i<100 ; i++){
		sin_tmp = sin_sig1.read(0)+0.5;
		sin_16 = ((int)(sin_tmp*0xFFFF))&0xFFFF;
		send_i2s(sin_16,sin_16);
	}
	
	sin_1.freq = 5e3;

	for(int i = 0 ; i<100 ; i++){
		sin_tmp = sin_sig1.read(0)+0.5;
		sin_16 = ((int)(sin_tmp*0xFFFF))&0xFFFF;
		send_i2s(sin_16,sin_16);
	}

	sc_start(bclk_period*10,SC_PS);
	

	sca_close_vcd_trace_file(tfp);
	//sca_close_tabular_trace_file(tfp);

	return 0;

}

