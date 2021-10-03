package d2d_project.simulations;

@license(LGPL);

import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.networklayer.ipv4.RoutingTableRecorder;
import inet.node.ethernet.Eth10G;
import inet.node.ethernet.Eth10M;
import inet.node.inet.Router;
import inet.node.inet.StandardHost;
import lte.world.radio.ChannelControl;
import lte.corenetwork.binder.LteBinder;
import lte.corenetwork.nodes.Ue;
import lte.corenetwork.nodes.eNodeB;
import lte.world.radio.LteChannelControl;
import lte.epc.PgwStandardSimplified;
import inet.visualizer.integrated.IntegratedCanvasVisualizer;
//import lte.common.omniscientEntity.OmniscientEntity;

network LTECell
{
    parameters:
        //int numUeCellPairs = default(5);
        //int numUeD2DPairs = default(0);
        @display("bgb=1961.8159,999.98395;cimage=lte/images/background/Lattakia.png;bgi=background/Lattakia");
    //@display("i=block/network2;bgb=991,558;bgi=background/budapest");
    submodules:
        visualizer: IntegratedCanvasVisualizer {
            @display("p=145,145");
        }
        channelControl: LteChannelControl {
            @display("p=50,25;is=s");
        }
        routingRecorder: RoutingTableRecorder {
            @displassy("p=50,75;is=s");
            @display("p=977.896,692.76");
        }
        configurator: Ipv4NetworkConfigurator {
            @display("p=50,125");
            config = xmldoc("demo.xml");
        }
        binder: LteBinder {
            @display("p=50,175;is=s");
        }
        server: StandardHost {
            @display("p=978,311;is=n;i=device/server");
        }
        router: Router {
            @display("p=978,417;i=device/smallrouter");
        }
        pgw: PgwStandardSimplified {
            nodeType = "PGW";
            @display("p=977,524;is=l");
        }
        eNodeB1: eNodeB {
            @display("p=613,372;is=vl");
        }
        eNodeB2: eNodeB {
            @display("p=512,165;is=vl");
        }
        eNodeB3: eNodeB {
            @display("p=249,459;is=vl");
        }
        ueTx1: Ue {
            @display("p=504,371");
        }
        ueRx1: Ue {
            @display("p=682.72,465.856");
        }
        ueTx2: Ue {
            @display("p=588,183");
        }
        ueRx2: Ue {
            @display("p=683,324");
        }
        ueTx3: Ue {
            @display("p=438,499");
        }
        ueRx3: Ue {
            @display("p=301,489");
        }
        ueTx4: Ue {
            @display("p=412,175");
        }
        ueRx4: Ue {
            @display("p=503,253");
        }
        ueTx5: Ue {
            @display("p=234,555");
        }
        ueRx5: Ue {
            @display("p=183,466");
        }

    connections:
        server.pppg++ <--> Eth10G <--> router.pppg++;
        router.pppg++ <--> Eth10G <--> pgw.filterGate;
        pgw.pppg++ <--> Eth10G <--> eNodeB1.ppp;
        pgw.pppg++ <--> Eth10G <--> eNodeB2.ppp;
        pgw.pppg++ <--> Eth10G <--> eNodeB3.ppp;

        eNodeB1.x2++ <--> Eth10G <--> eNodeB2.x2++;
        eNodeB1.x2++ <--> Eth10G <--> eNodeB3.x2++;

        eNodeB2.x2++ <--> Eth10G <--> eNodeB3.x2++;
}
