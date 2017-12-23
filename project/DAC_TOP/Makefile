
SRCDIR		=.
TOOLTOP		=$(SRCDIR)/../../FPGA_tools
VPATH		= $(SRCDIR):$(TOOLTOP):$(SRCDIR)/../DAC:$(SRCDIR)/../I2S
NSLINC		= -I$(SRCDIR) -I$(SRCDIR)/../DAC -I$(SRCDIR)/../I2S
ifndef DESIGN
DESIGN		= MAX10_FB
endif
TARGET		=
NSLFLAGS  	= -sim -neg_res $(NSLINC)
NSLSCFLAGS	= $(NSLFLAGS) -sc_split_header -sc_trace
VERIOPT		= 
SRCS		= DAC_TOP.nsl DAC.nsl i2s.nsl
LIBS		=


#######
# Systemc Env
#######
SCLIBS		= 
SCMOD		= FPGA.h LPF.h
#EXTRA_LIBS	=-X11


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
