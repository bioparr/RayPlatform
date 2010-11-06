source ../0parameters.sh
source ../0mix11-parameters.sh
source ../0mix13-parameters.sh
mpirun $MPIOPTS -np $nproc Ray.0 -p $p1left  $p1right -p $p2left $p2right  -s $r4541 -s $r4542 -s $r4543 
ln -s Ray-Contigs.fasta Assembly.fasta
ln -s $ref  Reference.fasta
echo Ray>Assembler.txt