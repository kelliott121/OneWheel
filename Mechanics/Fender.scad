$fn=72;

//for (qx = [-1, 1])
//{
//    for (qy = [-1, 1])
//    {
//        translate([10*qx, qy, 0])
//        rotate([0, 90*qx, 0])
//        intersection()
//        {
//            fender();
//            //translate([-7.5, 0, 0])
//            scale([qx, qy, 1])
//            cube([1000, 1000, 1000]);
//        }
//    }
//}

intersection()
{
    fender();
    
    cube([125, 150, 500], center=true);
}

module fender(diam=300, width=(215), thickness=5, length=(400), screwDistX=(190), screwDistY=(373.5), screwDiam=(1/4*25.4+1))
{
    fenderDiam = diam + thickness*2;
    mountOffset = 87.5;
    motorOffset = -46;
    supportOffset = 34.5;
    
    translate([0, 0, thickness/2 + mountOffset])
    difference()
    {
        cube([width, 248, thickness], center=true);
        
        union()
        {
            translate([motorOffset, 0, 0])
            for (xOffset = [-53.2/5, 53.2/5])
            {
                for (yOffset = [-53.2*.6, 53.2*.6])
                {
                    translate([xOffset, yOffset, 0])
                    cylinder(d=3.5, h=thickness*2, center=true);
                }
            }
            
            translate([supportOffset, 0, 0])
            for (yOffset = [-thickness*2.5, thickness*2.5])
            {
                for (xOffset = [-thickness*1.5, thickness*1.5])
                {
                    translate([xOffset, yOffset, 0])
                    cylinder(d=3.5, h=thickness*20, center=true);
                }
            }
            
            cube([25, 100, thickness*2], center=true);
        }
    }
    difference()
    {
        rotate([0, 90, 0])
        difference()
        {
            union()
            {
                cylinder(d=fenderDiam, h=width, center=true);
                cube([thickness*2, length, width], center=true);
            }
            
            union()
            {
                cylinder(d=diam, h=width, center=true);
                translate([width/2, 0, 0])
                cube([width, length, width], center=true);
            }
        }
        
        union()
        {
            translate([0, 0, fenderDiam/2 + thickness + mountOffset])
            cube([width, length, fenderDiam], center=true);
            for (xOffset = [-screwDistX/2, screwDistX/2])
            {
                for (yOffset = [-screwDistY/2, screwDistY/2])
                {
                    translate([xOffset, yOffset, 0])
                    cylinder(d=screwDiam, h=thickness*100, center=true);
                }
            }
        }
    }
}