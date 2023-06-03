###############################################################################
#                            Makefile do Zestawu11                            #
#                                Zadanie Sejfy                                #
#                                                                             #
#  Jan Kwinta                                                     03.06.2023  #
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
sourceS = Sejfy

# Objects
objectsS = $(addsuffix .o,$(sourceS))


#==============================================================================
# ZALEZNOSCI (kompilacja):

all: Sejfy.x
Sejfy.x: $(objectsS)

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
