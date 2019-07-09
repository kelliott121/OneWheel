$fn = 72;

axleBracket4();

module axleBracket(axleDiam=(5/8)*25.4+1.5, cubeWidth=22.225, thickness=5, screwDiam=6)
{
    difference()
    {
        union()
        {
            translate([0, cubeWidth*.25, 0])
            cube([cubeWidth*1.5, cubeWidth*1.5, cubeWidth], center=true);
            translate([0, -(-thickness/2 + cubeWidth/2), 0])
            cube([cubeWidth*5, thickness, cubeWidth], center=true);
            translate([0, 0, -(-thickness/2 + cubeWidth/2)])
            cube([cubeWidth*5, cubeWidth, thickness], center=true);
        }
        union()
        {
            translate([0, cubeWidth*.25, 0])
            cylinder(d=axleDiam, h=cubeWidth+1, center=true);
            
            for(xOffset = [-cubeWidth*1.25, cubeWidth*1.25])
            {
                translate([xOffset, 0, 0])
                rotate([90, 0, 0])
                cylinder(d=screwDiam, h=thickness*5, center=true);
            }
            
            for(xOffset = [-cubeWidth*2, cubeWidth*2])
            {
                translate([xOffset, 0, 0])
                cylinder(d=screwDiam, h=thickness*5, center=true);
            }
        }
    }
}

module axleBracket2(axleDiam=(5/8)*25.4+1.5, length=25.4*4, thickness=5, screwDiam=(1/4*25.4))
{
    tubeWidth = 25.4;
    bracketWidth = tubeWidth + thickness*2;
    
    difference()
    {
        cube([length, bracketWidth, bracketWidth], center=true);
        
        union()
        {
            cube([length+1, tubeWidth, tubeWidth], center=true);
            
            for (xOffset = [-1*length/3, 1*length/3])
            {
                translate([xOffset, 0, 0])
                rotate([90, 0, 0])
                cylinder(d=screwDiam+2, h=bracketWidth*2, center=true);
            }
        }
    }
    
    translate([0, bracketWidth/2 + thickness*2, 0])
    difference()
    {
        cube([bracketWidth, thickness*4, bracketWidth], center=true);
        rotate([90, 0, 0])
        cylinder(d=axleDiam, h=thickness*5, center=true);
    }
}

module axleBracket3(axleDiam=(5/8)*25.4+.5, length=25.4*4, thickness=5, screwDiam=(1/4*25.4))
{
    tubeWidth = 25.4;
    bracketWidth = tubeWidth + thickness*2;
    
    difference()
    {
        translate([0, 0, thickness/2 + 1])
        cube([length, bracketWidth, thickness+2], center=true);
        
        union()
        {
            translate([0, 0, 1])
            cube([length+1, tubeWidth+1, 2], center=true);
            
            for (xOffset = [-1*length/3, 1*length/3])
            {
                translate([xOffset, 0, 0])
                cylinder(d=screwDiam+2, h=bracketWidth*2, center=true);
            }
        }
    }
    
    translate([0, 0, thickness*2 + thickness+2])
    difference()
    {
        cube([bracketWidth, bracketWidth, thickness*4], center=true);
        cylinder(d=axleDiam, h=thickness*5, center=true);
    }
}

module axleBracket4(axleDiam=(5/8)*25.4+.5, length=25.4*4, thickness=5, screwDiam=(1/4*25.4), axleOffset=5)
{
    tubeWidth = 25.4;
    bracketWidth = tubeWidth + 1 + thickness*2;
    
    // Axle Holder
    translate([0, -bracketWidth/2 - axleOffset/2, bracketWidth/2])
    difference()
    {
        cube([bracketWidth, bracketWidth + axleOffset, bracketWidth], center=true);
        
        translate([0, -axleOffset/2, thickness/2])
        cylinder(d=axleDiam, h=bracketWidth-thickness, center=true);
    }
    
    translate([0, bracketWidth/2, (tubeWidth+thickness)/2])
    difference()
    {
        cube([length, bracketWidth, tubeWidth+thickness], center=true);
        
        union()
        {
            translate([0, 0, thickness/2])
            cube([length, tubeWidth+1, tubeWidth], center=true);
            
            for (xOffset = [-1*length/3, 1*length/3])
            {
                translate([xOffset, 0, thickness/2])
                rotate([90, 0, 0])
                cylinder(d=screwDiam+2, h=bracketWidth*2, center=true);
            }
        }
    }
}