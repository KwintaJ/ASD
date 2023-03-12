###############################################################################
#                            Makefile do Zestawu00                            #
#                            Implementacja wektora                            #
#                                                                             #
#  Jan Kwinta                                                     24.05.2022  #
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
head = Vector Functions

# Programs
sourceV = Vector

# Objects
objectsV = $(addsuffix .o,$(sourceV)) $(addsuffix .hpp,$(head))


#==============================================================================
# ZALEZNOSCI (kompilacja):

all: Vector.x
Vector.x: $(objectsV)

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