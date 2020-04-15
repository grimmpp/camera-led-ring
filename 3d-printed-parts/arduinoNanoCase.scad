
board_w = 18.5;
board_l = 43.5;
wall = 1.2;
h = 4.6+5;

camera_shoe();
base();

//lid();

module base() {

difference() {
    cube([2*wall+board_w,2*wall+board_l,wall+h]);
    
    
    translate([wall+(board_w-13)/2,wall,wall])
        cube([13,board_l,2]);
        
    translate([wall,wall,wall+2])
        cube([board_w,board_l,h]);
    
    //space of pinns
    translate([wall,5,wall]) cube([5,18,3]);  
    translate([wall+board_w-3,wall+4,wall]) cube([3,10,3]);
        
    //jack
    translate([wall+board_w/2-7.5/2,wall+board_l,wall+2+1.6+0.2])
        cube([7.5,wall,4]);
}

}


module lid() {

translate([wall,wall,wall+2+1.6])
difference() {
    translate([0,.5,0]) cube([board_w,board_l-1,h-wall-2-1.6]);
    translate([2.5,.5,0]) 
        cube([board_w-5,board_l,h-wall-2-1.6]);
    
    //space of pinns
    //cube([5,20,5]);
    translate([0,5-wall,0]) cube([5,18,h+5]);
    // button pins
    translate([board_w-2.5,4,0]) cube([2.5,10,h-wall-2-1.6]);
}

difference() {
    translate([0,0,h])
    cube([2*wall+board_w,2*wall+board_l,wall]);
    
    translate([0,5,0]) cube([5,18,h+5]);
    
    translate([wall+13,wall+8.5,wall])
        cylinder($fn=32, d=4.5,h=h);
        
}


} //lid


module camera_shoe() {
translate([0,wall+board_l/2-8,-4]) {
    //plate
    translate([1+board_w/2-8,1,0])
    hull() {
        cylinder($fn=32,h=2,d=2);
        translate([16,0,0]) cylinder($fn=32,h=2,d=2);
        translate([16,15,0]) cylinder($fn=32,h=2,d=2);
        translate([0,15,0]) cylinder($fn=32,h=2,d=2);
    }
    translate([4,0,2]) cube([12,17,2]);
    //cube([18,18,2]);
}}