########################
# source code makefile #
########################

CC = g++

CFLAGS = -O2 -Wall -fPIC
ROOTFLAG = `root-config --libs` `root-config --cflags`

TARGET = libE14DAQ.so

SRCS =  VMEController.cc FADCManager.cc E14DAQParContainer.cc 
SRCS += LocalCDTManager.cc TopCDTManager.cc EtOFCManager.cc
SRCS += ClusOFCManager.cc CSIFanoutCDTManager.cc VetoFanoutCDTManager.cc
SRCS += DetParContainer.cc

OBJS =  VMEController.o FADCManager.o E14DAQParContainer.o
OBJS += LocalCDTManager.o TopCDTManager.o EtOFCManager.o
OBJS += ClusOFCManager.o CSIFanoutCDTManager.o VetoFanoutCDTManager.o
OBJS += DetParContainer.o

all: $(TARGET)

.cc.o:
	$(CC) $(CFLAGS) -c  $< -lvme ${ROOTFLAG}

$(TARGET): $(OBJS) $(SRCS)
	$(CC) -shared -o $(TARGET) $(OBJS) -lvme ${ROOTFLAG}

clean:
	rm -f *.o *.so 
