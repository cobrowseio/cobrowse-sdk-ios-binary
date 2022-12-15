// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "CobrowseIO",
    platforms: [
        .macOS(.v10_13), .iOS(.v11)
    ],
    products: [
        .library(
            name: "CobrowseIO",
            targets: ["CBIOWrapper"]),
        .library(
            name: "CobrowseIOAppExtension",
            targets: ["CBIOAppExtensionWrapper"]
        )
    ],
    targets: [
        .target(
            name: "CBIOWrapper",
            dependencies: [
                .target(name: "CobrowseIO"),
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
    ]
)
