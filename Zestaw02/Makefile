###############################################################################
#                            Makefile do Zestawu02                            #
#                                    Kolejka                                  #
#                                                                             #
#  Jan Kwinta                                                     15.10.2022  #
###############################################################################

#==============================================================================
# Dostepne komendy: make, clean, tar

#==============================================================================
# Flagi, kompilator, rozszerzenia i inne:

CFLAGS = -O3 -Wall -pedantic -std=c++11
LDFLAGS = -Wall -pedantic -std=c++11 -s
LDLIBS = -lm
CO = g++
.SUFFIXES: .c .cpp .o .x .h .hpp
DIR = $(notdir $(CURDIR))


#==============================================================================
# NAZWY PLIKOW:

# Headers
headers = ArrayQueue LinkedQueue

# Programs
sourceQueue = Queue
sourceRadix = Radix
sourceGen = Generator

# Objects
objectsQueue = $(addsuffix .o,$(sourceQueue)) $(addsuffix .hpp,$(headers))
objectsRadix = $(addsuffix .o,$(sourceRadix)) $(addsuffix .hpp,$(headers))
objectsGen = $(addsuffix .o,$(sourceGen))


#==============================================================================
# ZALEZNOSCI (kompilacja):

all: Queue.x Radix.x Generator.x
Queue.x: $(objectsQueue)
Radix.x: $(objectsRadix)
Generator.x: $(objectsGen)

%.o: %.cpp
	$(CO) $(CFLAGS) -c -o $@ $<

%.x: %.o
	$(CO) $(LDFLAGS) -o $@ $^ $(LDLIBS)

#==============================================================================
# Sprzataczka

.PHONY: clean tar
clean:
	rm -f *.o  *~ *.a *.so *.x core core* a.out *.exe *.in *.out

# Archiwizacja i kompresja
tar: clean
	(cd ../; tar -cvzf Jan_Kwinta_$(DIR).tar.gz  $(DIR) )
