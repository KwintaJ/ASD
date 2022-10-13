###############################################################################
#                            Makefile do Zestawu01                            #
#                                     Stos                                    #
#                                                                             #
#  Jan Kwinta                                                     07.10.2022  #
###############################################################################

#==============================================================================
# Dostepne komendy: make, run1, run2, clean, tar

#==============================================================================
# Flagi, kompilator, rozszerzenia i inne:

CFLAGS = -O2 -Wall -pedantic -std=c++11
LDFLAGS = -Wall -pedantic -std=c++11 -s
LDLIBS = -lm
CO = g++
.SUFFIXES: .c .cpp .o .x .h .hpp
DIR = $(notdir $(CURDIR))


#==============================================================================
# NAZWY PLIKOW:

# Headers
headers = ArrayStack LinkedStack

# Programs
sourceStack = Stack
sourceGen = Generator
sourceONP = ONP

# Objects
objectsStack = $(addsuffix .o,$(sourceStack)) $(addsuffix .hpp,$(headers))
objectsGen = $(addsuffix .o,$(sourceGen))
objectsONP = $(addsuffix .o,$(sourceONP)) $(addsuffix .hpp,$(headers))


#==============================================================================
# ZALEZNOSCI (kompilacja):

all: Stack.x Generator.x ONP.x
Stack.x: $(objectsStack)
Generator.x: $(objectsGen)
ONP.x: $(objectsONP)

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
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )