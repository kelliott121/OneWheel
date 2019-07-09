$fn = 72;

bracket();
//cube([100, 1, 25.4]);

module bracket(alumThickness=(1/8)*25.4, alumWidth=(1)*25.4, screwDiam=(1/4)*25.4+1.5, screwlength=(1)*25.4, thickness=4)
{
    cubeSide = alumWidth - alumThickness*2;
    
    difference()
    {
        // Bracket
        translate([0, 0, alumThickness])
        union()
        {
            // XY leg
            intersection()
            {
                translate([0, 0, thickness/2])
                rotate([0, 0, 45])
                cube([cubeSide*3.5, cubeSide*3.5, thickness], center=true);
                
                cube([cubeSide*4, cubeSide*4, thickness*4]);
            }
            // XZ leg
            translate([cubeSide, thickness/2, cubeSide/2 + alumThickness])
            rotate([90, 0, 0])
            cube([cubeSide*2, cubeSide, thickness], center=true);
            
            // YZ leg
            translate([thickness/2, cubeSide, cubeSide/2 + alumThickness])
            rotate([0, 90, 0])
            cube([cubeSide, cubeSide*2, thickness], center=true);
        }
        
        // Holes
        union()
        {
            translate([alumWidth/2, alumWidth/2, 0])
            rotate([0, 0, 0])
            cylinder(d=screwDiam, h=cubeSide*8, center=true);
            
            translate([cubeSide*1.25, 0, alumWidth/2])
            union()
            {
                rotate([90, 0, 0])
                cylinder(d=screwDiam, h=cubeSide*8, center=true);
                
                translate([0, thickness + 3, 0])
                cube([12, 6, 20], center=true);
            }
            
            translate([0, cubeSide*1.25, alumWidth/2])
            union()
            {
                rotate([0, 90, 0])
                cylinder(d=screwDiam, h=cubeSide*8, center=true);
                
                translate([thickness + 3, 0, 0])
                cube([6, 12, 20], center=true);
            }
        }
    }
}