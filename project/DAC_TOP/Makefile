
SRCDIR		=.
TOOLTOP		=$(SRCDIR)/../../FPGA_tools
VPATH		= $(SRCDIR):$(TOOLTOP):$(SRCDIR)/../DAC:$(SRCDIR)/../I2S:$(SRCDIR)/../OVS:$(SRCDIR)/sim
NSLINC		= -I$(SRCDIR) -I$(SRCDIR)/../DAC -I$(SRCDIR)/../I2S -I$(SRCDIR)/../OVS
ifndef DESIGN
DESIGN		= MAX10_FB
endif
TARGET		=
NSLFLAGS  	= -O2 -neg_res $(NSLINC)
NSLSCFLAGS	= $(NSLFLAGS) -sc_split_header -sc_trace #-sc_bool
VERIOPT		= 
SRCS		= DAC_TOP.nsl DAC.nsl i2s.nsl OVS.nsl
LIBS		=


#######
# Systemc Env
#######
SCLIBS		= sin_source.cpp
SCMOD		= FPGA.h LPF.h sin_source.h
#EXTRA_LIBS	=-X11


CXXFLAGS	= -O3 -I$(SRCDIR)/sim



include $(TOOLTOP)/mk/env.mk
include $(TOOLTOP)/mk/nsl.mk
include $(TOOLTOP)/mk/quartus.mk
include $(TOOLTOP)/mk/iverilog.mk
include $(TOOLTOP)/mk/verilator.mk
include $(TOOLTOP)/mk/systemc.mk

clean:
	rm -rf - $(WORKDIR)
	rm -rf - $(DEBUGDIR)
