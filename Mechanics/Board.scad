$fn=36;

use "Bracket.scad";

frame();
translate([0, 0, 25.4/16])
deck();

for (xScale = [-1, 1])
{
    scale([xScale, 1, 1])
    union()
    {
        translate([12.5, 0, -19])
        rotate([0, 90, 0])
        cylinder(d=290, h=25);
        
        translate([37.5, 0, -19])
        rotate([0, 90, 0])
        cylinder(d=290, h=25);
    }
}

module deck(crossWidth=225, boardLength=750)
{
    color([255/255, 222/255, 173/255])
    translate([0, 0, 5.2/2])
    for (yOffset = [-(boardLength-crossWidth)/2, (boardLength-crossWidth)/2])
    {
        translate([0, yOffset, 0])
        cube([crossWidth, crossWidth, 5.2], center=true);
    }
}

module frame(alumThickness = 25.4/16, alumWidth=25.4, crossWidth=225, boardLength=750)
{
    translate([0, 0, alumThickness/2])
    union()
    {
        for (scaleX = [-1, 1])
        {
            scale([scaleX, 1, 1])
            translate([crossWidth/2, 0, 0])
            translate([-(alumWidth/2 - alumThickness), 0, 0])
            rotate([0, 180, 0])
            angleAluminum(length=boardLength, width=alumWidth, thickness=alumThickness);
        }

        for (scaleY = [-1, 1])
        {
            scale([1, scaleY, 1])
            translate([0, boardLength/2, 0])
            translate([0, -(alumWidth/2), -alumThickness])
            rotate([0, 180, 90])
            angleAluminum(length=crossWidth, width=alumWidth, thickness=alumThickness);
            
            scale([1, scaleY, 1])
            translate([0, -(boardLength/2 - crossWidth), 0])
            translate([0, -(alumWidth/2), -alumThickness])
            rotate([0, 180, 90])
            angleAluminum(length=crossWidth, width=alumWidth, thickness=alumThickness);
        }
    }
}

module angleAluminum(length, width, thickness)
{
    color([173/255, 178/255, 189/255])
    union()
    {
        cube([width, length, thickness], center=true);
        translate([-(width/2 - thickness/2), 0, (width/2 - thickness/2)])
        cube([thickness, length, width], center=true);
    }
}