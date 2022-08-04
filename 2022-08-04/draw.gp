set yrange [0:100000]

# set terminal png font "/usr/share/fonts/truetype/arphic/uming.ttc,20 "
# set output "statistics.png"

set title "竞赛图求曼哈顿通路"
set ylabel "执行时间/纳秒" font "Times-Italic,20"
set xlabel "顶点数量" font "Times-Italic,20"

plot "origin" with linespoints linewidth 2 smooth unique title "原版", \
     "op1" with linespoints linewidth 2 smooth unique title "O3优化";
