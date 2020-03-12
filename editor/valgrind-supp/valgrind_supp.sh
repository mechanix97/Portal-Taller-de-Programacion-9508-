# create minimalraw.log file for crete supression file
valgrind --leak-check=full --show-reachable=yes --error-limit=no --gen-suppressions=all --log-file=minimalraw.log ../build/portal_editor

# create minimal supp
chmod a+x parse_valgrind_suppressions.sh
cat ./minimalraw.log | ./parse_valgrind_suppressions.sh > minimal.supp

# check memory leaks

# run valgrind and delete memory leaks
valgrind --leak-check=full --show-reachable=yes --error-limit=no --suppressions=./minimal.supp --gen-suppressions=all --log-file=minimalraw.log ../build/portal_editor

