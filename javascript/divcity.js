/*
*  divcity.js (C) Adrián Arroyo Calle
*  JavaScript code for DivCity
*/
function Casilla(id){
	this.id=id;


	
	switch(id){
		case "CLEAN": 
	
			this.bitmap="media/color_block.png";

	}




}

function OnLoad(){
	var canvas=document.getElementById("canvas").getContext("2d");
	var escribir=0;
    	var ax=1,ay=1,bx=0,by=0;
    	var lineasx,lineasy;
	money=50000;
	bitmapactual=new Array();
	var count;
	//canvas.scale(0.5,0.5);
	canvas.mozImageSmoothingEnabled = false;
	for(lineasy=1;lineasy!=28;lineasy++){

		for(lineasx=1;lineasx!=19;lineasx++){
            		var bloque="CLEAN";
			var img=new Image();
			
			bitmapactual[count]=new Casilla(bloque);
			img.src=bitmapactual[count].bitmap;
            		//canvas.drawImage(img,bx*73/6,by*53/6);//,53/2,73/2);
			canvas.drawImage(img,(bx/2)*img.width,(by/2)*img.height,img.width,img.height);
           		// bitmapactual[count]->x=bx*73/2;
           		// bitmapactual[count]->y=by*53/2;
            		count++;
            		bx+=2;
			
        	}
        	for(lineasx=1;lineasx!=19;lineasx++){
            		var bloque="CLEAN";
			var img=new Image();
			bitmapactual[count]=new Casilla(bloque);
			img.src=bitmapactual[count].bitmap;
            		//canvas.drawImage(img,ax*73,ay*53,53,73);
			canvas.drawImage(img,(ax/2)*img.width,(ay/2)*img.height,img.width,img.height);
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


