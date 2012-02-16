default: profile
profile: clean both
	@echo ------
	@time bin/eq-naive
	@echo ------
	@time bin/eq-fast
	@echo ------
	@echo Done.
both: naive fast
naive:
	mkdir -p obj bin
	gcc -fPIC -c -DNAIVE -o obj/eq-naive.o src/eq.c
	gcc -o bin/eq-naive obj/eq-naive.o
fast:
	mkdir -p obj bin
	gcc -fPIC -c -DFAST -o obj/eq-fast.o src/eq.c
	gcc -o bin/eq-fast obj/eq-fast.o
clean:
	@echo Cleaning...
	-rm -R obj bin
