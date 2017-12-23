#include <systemc-ams.h>


SC_MODULE(LPF){

	//I/O
	//sc_core::sc_in<double> in;
	sca_tdf::sca_in<double> in;
	sca_tdf::sca_out<double> out;

	//Module
	sca_eln::sca_tdf::sca_vsource vin;
	sca_eln::sca_tdf::sca_vsink vout;

	sca_eln::sca_r r;
	sca_eln::sca_c c;

	LPF(sc_core::sc_module_name, double r_value, double c_value)
	:in("in"), out("out"), vin("vin"), vout("vout"), r("r",r_value), c("c",c_value), gnd("gnd")
	{
		vin.inp(in);
		vin.p(n1);
		vin.n(gnd);

		r.n(n1);
		r.p(n2);

		c.n(n2);
		c.p(gnd);

		vout.p(n2);
		vout.n(gnd);
		vout.outp(out);
	}

	private:
		sca_eln::sca_node n1,n2;
		sca_eln::sca_node_ref gnd;
};
