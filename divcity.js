/*
*  divcity.js (C) Adrián Arroyo Calle
*  JavaScript code for DivCity
*/

function OnLoad(){
	var canvas=document.getElementById("canvas").getContext("2d");
	var escribir=0;
    	var ax=1,ay=1,bx=0,by=0;
    	var lineasx,lineasy;
	money=50000;
	var count;
	for(lineasy=1;lineasy!=28;lineasy++){

		for(lineasx=1;lineasx!=19;lineasx++){
            		var bloque="CLEAN";
			var bitmapactual[count]=new Casilla(bloque);

            canvas.drawImage(bitmapactual[count].bitmap,bx*73/2,by*53/2,73,53);
           // bitmapactual[count]->x=bx*73/2;
           // bitmapactual[count]->y=by*53/2;
            count++;
            bx+=2;


        }
        for(lineasx=1;lineasx!=19;lineasx++){
            var bloque="CLEAN";


            var bitmapactual[count]=new Casilla(bloque);
            canvas.drawImage(bitmapactual[count].bitmap,ax*73/2,ay*53/2,73,53);
           // bitmapactual[count]->x=ax*73/2;
           // bitmapactual[count]->y=ay*53/2;
            ax+=2;
            count++;


        }

        ay+=2;
        ax=1;
        by+=2;
        bx=0;


    }



}

function Casilla(id){
	this.id=id;


	
	switch(id){
		case "CLEAN": this.bitmap="media/template.png";

	}




}
