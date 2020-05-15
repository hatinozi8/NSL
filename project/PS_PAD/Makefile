
SRCDIR		=.
TOOLTOP		=$(SRCDIR)/../../FPGA_tools
VPATH		= $(SRCDIR):$(TOOLTOP)
NSLINC		= -I$(SRCDIR) 
ifndef DESIGN
#DESIGN		= DE0_CV
DESIGN		= MAX10_FB
endif
TARGET		=
NSLFLAGS  	= -sim -neg_res $(NSLINC)
NSLSCFLAGS	= $(NSLFLAGS) -sc_split_header -sc_trace
VERIOPT		= 
SRCS		= PS_PAD_S.nsl PS_PAD_M.nsl HEX.nsl
LIBS		=


CXXFLAGS	= -O3



include $(TOOLTOP)/mk/env.mk
include $(TOOLTOP)/mk/nsl.mk
include $(TOOLTOP)/mk/quartus.mk
include $(TOOLTOP)/mk/iverilog.mk
include $(TOOLTOP)/mk/verilator.mk
include $(TOOLTOP)/mk/systemc.mk

clean:
	rm -rf - $(WORKDIR)
	rm -rf - $(DEBUGDIR)
