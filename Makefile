SRC_DIR  = ./src
COMP_DIR = ./components
BIN_DIR  = ./bin
TEST_DIR = ./tests
MAIN     = ./src/main.cpp
VERSION  = -std=c++11

COMPONENTS_C = ${shell find ${COMP_DIR} -name *.cpp}
COMPONENTS_O = ${COMPONENTS_C:.cpp=.o}

DATA_TEST_DIR 		 = ${TEST_DIR}/DataTest
SOLITAIRE_TEST_DIR = ${TEST_DIR}/SolitaireTest
USER_TEST_DIR 		 = ${TEST_DIR}/UserTest

all: main.out

main.out: ${COMPONENTS_O}
	g++ ${VERSION} $(MAIN) ${COMPONENTS_O} -o ${BIN_DIR}/main.out

${COMPONENTS_O}: ${COMPONENTS_C}
	g++ ${VERSION} -c $(addsuffix .cpp, $*) -o $@

run:
	${BIN_DIR}/main.out

test: ${DATA_TEST_DIR}/DataTest.out ${SOLITAIRE_TEST_DIR}/SolitaireTest.out ${USER_TEST_DIR}/UserTest.out
	${DATA_TEST_DIR}/DataTest.out && ${SOLITAIRE_TEST_DIR}/SolitaireTest.out && ${USER_TEST_DIR}/UserTest.out

${DATA_TEST_DIR}/DataTest.out: ${DATA_TEST_DIR}/DataTest.cpp
	g++ -o ${DATA_TEST_DIR}/DataTest.out ${DATA_TEST_DIR}/DataTest.cpp components/Database/Database.o components/User/User.o

${SOLITAIRE_TEST_DIR}/SolitaireTest.out: ${SOLITAIRE_TEST_DIR}/SolitaireTest.cpp
	g++ -o ${SOLITAIRE_TEST_DIR}/SolitaireTest.out ${SOLITAIRE_TEST_DIR}/SolitaireTest.cpp components/Solitaire/Solitaire.o components/OnePlayer/OnePlayer.o components/Dealer/Dealer.o components/User/User.o

${USER_TEST_DIR}/UserTest.out: ${USER_TEST_DIR}/UserTest.cpp
	g++ -o ${USER_TEST_DIR}/UserTest.out ${USER_TEST_DIR}/UserTest.cpp components/User/User.o

clean:
	rm ${COMPONENTS_O}
	rm ${BIN_DIR}/main.out

test_clean:
	rm ${shell find ${TEST_DIR} -name *.out}
