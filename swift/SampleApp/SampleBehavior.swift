//
//  SampleBehavior.swift
//  SampleApp
//
//  Created by Stephen Schalkhauser on 7/12/17.
//  Copyright © 2017 P2UX, Inc. All rights reserved.
//

import UIKit
import P2UXApp

/* Listed below are possible behaviors that can be customized for your app.
 Many feature the line:
 
 if ([def.systemType isEqualToString:@"xxxxx"])
 
 The user should replace "xxxxx" with an appropriate name of the item being customized.
 
 Other possible behaviors that can be customized can be found in P2UXAppBehavior.
*/

class SampleBehavior: P2UXAppBehavior {

    override func createViewController(withDef def: P2UXDefinition!, cache: Bool, index: Any!, data: Any!, viewDelegate: P2UXViewContainerDelegate!) -> P2UXViewController! {
        if def.systemType == "xxxxx" {
            return ViewController(view: def, behavior: self, cache: cache, index: index, data: data, viewDelegate: viewDelegate);
        }
        return super.createViewController(withDef: def, cache: cache, index: index, data: data, viewDelegate: viewDelegate)
    }
}
