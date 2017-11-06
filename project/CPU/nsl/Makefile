
SRCDIR		= ./
VPATH		= $(SRCDIR)
NSLINC		= -I$(SRCDIR)
ifndef DESIGN
DESIGN		= DE0_CV
endif
TARGET		=
#NSLFLAGS  	= -sim -neg_res $(NSLINC)
NSLFLAGS	= -O2 -neg_res
NSLSCFLAGS	= $(NSLFLAGS) -sc_split_header -sc_trace
VERIOPT		= 
SRCS		= cpu.nsl
LIBS		=

SCLIBS		=
SCMOD		= 

CXXFLAGS	= -O3


TOOLTOP		=$(SRCDIR)/../../../FPGA_tools

include $(TOOLTOP)/mk/env.mk
include $(TOOLTOP)/mk/nsl.mk
include $(TOOLTOP)/mk/quartus.mk
include $(TOOLTOP)/mk/iverilog.mk
include $(TOOLTOP)/mk/verilator.mk
include $(TOOLTOP)/mk/systemc.mk
