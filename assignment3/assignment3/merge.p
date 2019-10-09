 set autoscale                        # scale axes automatically
      unset log                              # remove any log-scaling
      unset label                            # remove any previous labels
      set xtic auto                          # set xtics automatically
      set ytic auto                          # set ytics automatically
	  set tics font "Helvetica,10"
      set title "MERGE SORT"
      set xlabel "Number of Hidden Layers"
      set ylabel "Accucarcy (%)"
      plot  "merge.txt" using 1:2 title 'average' with linespoints, \
            "merge.txt" using 1:3 title 'best'  with linespoints,\
            "merge.txt" using 1:4 title 'worst'  with linespoints
			pause 30

            
