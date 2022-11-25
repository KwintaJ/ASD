###############################################################################
#                            Makefile do Zestawu05                            #
#                         Proste algorytmy sortowania                         #
#                                                                             #
#  Jan Kwinta                                                     25.11.2022  #
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
sourceBS = BubbleSort
sourceSS = SelectionSort
sourceIS = InsertionSort
sourceGen = Generator

# Objects
objectsBS = $(addsuffix .o,$(sourceBS))
objectsSS = $(addsuffix .o,$(sourceSS))
objectsIS = $(addsuffix .o,$(sourceIS))
objectsGen = $(addsuffix .o,$(sourceGen))


#==============================================================================
# ZALEZNOSCI (kompilacja):

all: BubbleSort.x SelectionSort.x InsertionSort.x Generator.x
BubbleSort.x: $(objectsBS)
SelectionSort.x: $(objectsSS)
InsertionSort.x: $(objectsIS)
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
