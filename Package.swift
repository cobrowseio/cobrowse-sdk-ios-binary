// swift-tools-version:5.7
import PackageDescription

let package = Package(
    name: "CobrowseIO",
    platforms: [
        .macOS(.v10_13), .iOS(.v12)
    ],
    products: [
        .library(
            name: "CobrowseIO",
            targets: ["CBIOWrapper"]),
        .library(
            name: "CobrowseIOAppExtension",
            targets: ["CBIOAppExtensionWrapper"]
        ),
        .executable(name: "cbio",
                    targets: ["cbio-cli"]),
        .plugin(name: "CobrowseSelectorsPlugin",
                targets: ["GenerateCobrowseSelectors"])
    ],
    targets: [
        .target(
            name: "CBIOWrapper",
            dependencies: [
                "CobrowseIO"
            ],
            path: "wrapper"),
        .target(
            name: "CBIOAppExtensionWrapper",
            dependencies: [
                .target(name: "CobrowseIOAppExtension"),
            ],
            path: "wrapper-app-extension"),
        .binaryTarget(
            name: "CobrowseIO",
            path: "CobrowseIO.xcframework"),
        .binaryTarget(
            name: "CobrowseIOAppExtension",
            path: "CobrowseIOAppExtension.xcframework"),
        .plugin(
            name: "GenerateCobrowseSelectors",
            capability: .command(
                intent: .custom(
                    verb: "generate-cobrowse-selectors",
                    description: "Generate Cobrowse.io selectors"),
            permissions: [
                .writeToPackageDirectory(reason: "We need to modify your source to add the Cobrowse.io selectors.")
            ]),
            dependencies: [ "cbio-cli" ]
        ),
        .binaryTarget(
            name: "cbio-cli",
            path: "./cbio.artifactbundle"
        ),
    ]
)