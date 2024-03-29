###############################################################################
#                             Makefile do Projektu                            #
#                                  Prostokat                                  #
#                                                                             #
#  Jan Kwinta                                                     15.01.2023  #
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

# Programs
sourceP = Prostokat
sourcePB = ProstokatBrute
sourceGen = Generator
sourceTest = Tester

# Headers
headersP = Functions Point IntervalTree Vector LinkedQueue 
headersPB = Point 

# Objects
objectsP = $(addsuffix .o,$(sourceP)) $(addsuffix .hpp,$(headersP))
objectsPB = $(addsuffix .o,$(sourcePB)) $(addsuffix .hpp,$(headersPB))
objectsGen = $(addsuffix .o,$(sourceGen))
objectsTest = $(addsuffix .o,$(sourceTest))

#==============================================================================
# ZALEZNOSCI (kompilacja):

all: Prostokat.x ProstokatBrute.x Generator.x Tester.x

Prostokat.x: $(objectsP)
ProstokatBrute.x: $(objectsPB)
Generator.x: $(objectsGen)
Tester.x: $(objectsTest)

test: all
	./Tester.x

%.o: %.cpp
	$(CO) $(CFLAGS) -c -o $@ $<

%.x: %.o
	$(CO) $(LDFLAGS) -o $@ $^ $(LDLIBS)


#==============================================================================
# Sprzataczka

.PHONY: clean tar
clean:
	rm -f *.o  *~ *.a *.so *.x core core* a.out *.exe *.in *.out

cleanTestData:
	rm -f ./tests/in/*.in ./tests/out/*.out ./tests/toTest/*.out

# Archiwizacja i kompresja
tar: clean
	(cd ../; tar -cvzf Jan_Kwinta_$(DIR).tar.gz  $(DIR) )


