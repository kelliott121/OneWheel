$fn = 72;

ZOffset = (3/8)*25.4;

difference()
{
    union()
    {
        translate([2, 0, 0])
        scale([-1, 1, 1])
        rotate([0, -90, 0])
        drillGuide([((3/4)*25.4), ((1 + 11/16)*25.4), ((3/4)*25.4)+25.4, ((1 + 11/16)*25.4)+25.4], [ZOffset, ZOffset, 25.4-ZOffset, 25.4-ZOffset]);

        translate([-2, 0, 0])
        rotate([0, -90, 0])
        drillGuide([((3/4)*25.4), ((1 + 11/16)*25.4), ((3/4)*25.4)+25.4, ((1 + 11/16)*25.4)+25.4], [ZOffset, ZOffset, 25.4-ZOffset, 25.4-ZOffset]);
    }
    
    translate([0, 0, 25 + 13 + 2.5])
    cube([500, 500, 50], center=true);
}

module drillGuide(yOffsets, zOffsets)
{
    drillSize = (1/8)*25.4+.5;
    width = 1*25.4+1;
    
    difference()
    {
        translate([-1, 0, -1])
        cube([width+2, width*3, width+2]);
        
        union()
        {
            translate([3, 0, 0])
            cube([width, width*3, width]);
            
            for (index = [0:(len(yOffsets)-1)])
            {
                translate([-1, yOffsets[index], zOffsets[index]])
                rotate([0, 90, 0])
                cylinder(d=drillSize, h=width+2);
            }
        }
    }
}