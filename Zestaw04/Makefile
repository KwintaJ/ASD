###############################################################################
#                            Makefile do Zestawu03                            #
#                                    Lista I                                  #
#                                                                             #
#  Jan Kwinta                                                     28.10.2022  #
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
sourceCL = CursorList
sourceAL = ArrayList
sourceGen = Generator

# Objects
objectsCL = $(addsuffix .o,$(sourceCL)) $(addsuffix .hpp,$(sourceCL))
objectsAL = $(addsuffix .o,$(sourceAL)) $(addsuffix .hpp,$(sourceAL))
objectsGen = $(addsuffix .o,$(sourceGen))


#==============================================================================
# ZALEZNOSCI (kompilacja):

all: CursorList.x ArrayList.x Generator.x
CursorList.x: $(objectsCL)
ArrayList.x: $(objectsAL)
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
