
metaRepet=30


if [ $# -ne 2 ] 
then
   echo "run <N> <nb_repets>"
else
	n=$1
	nb_rep=$2
	for i in `seq 1 1 $metaRepet`
	do
		./driver $n $nb_rep
	done
fi
