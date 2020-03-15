d= 80;
s = 24;


difference() {
intersection() {
difference() {
    cylinder($fn=80, d=d+20, h=16);
    translate([0,0,-1]) cylinder($fn=80, d=d, h=16+2);
}

translate([d/2,-sqrt(s*s+s*s)/2,0]) rotate([0,0,45]) cube([s,s,16]);
}

//screw
translate([30,0,8]) rotate([0,90,0]) import("bolt_25x8.stl");
}
