set yrange [0:15000]

# set terminal png font " Times_New_Roman,12 "

set ylabel "time /ns" font "Times-Italic,22"
set xlabel "size of linked list" font "Times-Italic,22"

plot "data" with linespoints linewidth 2 smooth unique title "原版", \
     "data2" with linespoints linewidth 2 smooth unique title "inline优化", \
     "O3otimization" with linespoints linewidth 2 smooth unique title "O3优化", \
     "branch-op" with linespoints linewidth 2 smooth unique title "O3优化+分支优化"